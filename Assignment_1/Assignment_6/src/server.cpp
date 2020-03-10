//
// server.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2019 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <fstream>
#include "Image.hpp"
#include <fmt/printf.h>
#include <experimental/filesystem>

using boost::asio::ip::tcp;

std::string make_daytime_string()
{
	using namespace std; // For time_t, time and ctime;
	auto now = time(nullptr);
	return ctime(&now);
}

bool read_image(std::string& img_name, Image* img)
{
	std::ifstream file(img_name, std::ios::in | std::ios::binary | std::ios::ate);
	if (file.is_open())
	{
		const auto size = file.tellg();
		img->size = size;
		const auto mem_block = new char[size];
		file.seekg(0, std::ios::beg);
		file.read(mem_block, size);
		img->bytes = mem_block;
		file.close();

		std::cout << "the entire file content is in memory";
		return true;
	}
	std::cout << "Unable to open file";
	return false;
}

int main()
{
	try
	{
		boost::asio::io_context io_context;

		tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 5000));

		for (;;)
		{
			tcp::socket socket(io_context);
			acceptor.accept(socket);

			auto message = make_daytime_string();

			auto img = new Image();
			std::string image_name = "cat.jpg";
			auto img_found = read_image(image_name, img);
			if (!img_found)
			{
				fmt::print("Failed to locate image {}", image_name);
				break;
			}

			boost::system::error_code ignored_error;
			write(socket, boost::asio::buffer(img->bytes, img->size), ignored_error);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
