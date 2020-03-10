//
// client.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2019 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <conio.h>
#include <fstream>

using boost::asio::ip::tcp;

void write_to_file(const std::string f_name, char* buffer, size_t len)
{
	std::ofstream outfile(f_name, std::ios::binary);

	for (auto i = 0; i <= len; i++)
	{
		outfile << buffer[i];
	}
	outfile.close();
};

int main(int argc, char* argv[])
{
	try
	{
		if (argc != 2)
		{
			std::cerr << "Usage: client <host>" << std::endl;
			return 1;
		}

		boost::asio::io_context io_context;

		tcp::resolver resolver(io_context);
		const auto endpoints = resolver.resolve(argv[1], "5000");

		tcp::socket socket(io_context);
		boost::asio::connect(socket, endpoints);

		for (;;)
		{
			boost::array<char, 17618> buf;
			boost::system::error_code error;

			const auto len = socket.read_some(boost::asio::buffer(buf), error);

			if (error == boost::asio::error::eof)
				break; // Connection closed cleanly by peer.
			if (error)
				throw boost::system::system_error(error);
			// Some other error.

			write_to_file("cat_out.jpg", buf.c_array(), len);

			std::cout << "File downloaded!" << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// So the window does not close upon end of execution
	_getch();
	return 0;
}
