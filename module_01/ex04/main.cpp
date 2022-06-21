#include <iostream>
#include <fstream>

void	process_file(std::ifstream& file_in, std::ofstream& file_out,
						std::string& s1, std::string& s2)
{
	std::string		buf;
	size_t			i;
	size_t 			found;

	while (!file_in.eof())
	{
		std::getline(file_in, buf);
		if (file_in.fail())
		{
			std::cerr << "Error while reading the file" << std::endl;
			file_in.close();
			file_out.close();
			std::exit(1);
		}
		i = 0;
		while (s1.length() && (found = buf.find(s1, i)) != buf.npos)
		{
			file_out << buf.substr(i, found - i) << s2;
			i = found + s1.length();
		}
		file_out << buf.substr(i, buf.length() - i);
		if (!file_in.eof())
			file_out << std::endl;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string		filename(argv[1]);
		std::ifstream	file_in(filename);
		std::ofstream	file_out;
		std::string	s1(argv[2]);
		std::string s2(argv[3]);

		if (!file_in)
		{
			std::cerr << "Error while opening the input file" << std::endl;
			std::exit(1);
		}
		file_out.open(filename + ".replace");
		if (!file_out)
		{
			std::cerr << "Error while opening the output file" << std::endl;
			file_in.close();
			std::exit(1);
		}
		process_file(file_in, file_out, s1, s2);
		file_in.close();
		file_out.close();
	}
	else
		std::cerr << "Wrong number of arguments" << std::endl;
	return (0);
}