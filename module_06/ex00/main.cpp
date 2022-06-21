#include <iostream>
#include "Conversion.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Bad arguments" << std::endl;
		return (1);
	}
	Conversion::convert(argv[1]);
	return 0;
}
