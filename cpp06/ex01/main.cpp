#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	Data *data = new Data(42);
	std::cout << "data(address): " << data << std::endl;
	std::cout << "data->_value: " << data->_value << std::endl;
	uintptr_t raw = Serializer::serializer(data);
	std::cout << "raw（uintptr_t）: " << raw << std::endl;
	Data *deserializedData = Serializer::deserializer(raw);
	std::cout << "data(address):" << std::endl
			  << data << std::endl;
	std::cout << "deserializedData(address)" << std::endl
			  << deserializedData << std::endl;
	std::cout << "deserializedData->_value: " << deserializedData->_value << std::endl;

	delete data;
	return 0;
}
