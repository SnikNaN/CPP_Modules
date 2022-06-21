#include <iostream>

struct	Data
{
	unsigned int	i;
	char 			c;
	std::string		str;
};

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main()
{
	Data	data;
	uintptr_t	raw;
	Data*	deserialized;

	data.i = 1024;
	data.c = '#';
	data.str = "Hello, world!";

	raw = serialize(&data);
	deserialized = deserialize(raw);

	std::cout << "Data address: " << &data << std::endl;
	std::cout << "Fields: " << data.i << " " << data.c << " " << data.str
		<< std::endl << std::endl;
	std::cout << "Deserialized address: " << deserialized << std::endl;
	std::cout << "Fields: " << deserialized->i << " " << deserialized->c << " "
		<< deserialized->str << std::endl;
	return 0;
}
