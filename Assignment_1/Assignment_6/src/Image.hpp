#pragma once

class Image
{
public:
	Image(): bytes(nullptr), size(0)
	{
	}

	~Image()
	{
		if (bytes != nullptr)
		{
			delete[] bytes;
		}
	}

	char* bytes;
	size_t size;
};
