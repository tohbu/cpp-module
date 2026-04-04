#include "Serializer.hpp"

uintptr_t Serializer::serializer(Data *ptr)
{
	uintptr_t result;
	result = reinterpret_cast< uintptr_t >(ptr);
	return result;
}

Data *Serializer::deserializer(uintptr_t raw)
{
	Data *result;
	result = reinterpret_cast< Data * >(raw);
	return result;
}