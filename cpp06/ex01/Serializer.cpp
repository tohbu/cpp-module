#include "Serializer.hpp"

Serializer::Serializer()
{
}
Serializer::Serializer(const Serializer &src)
{
	(void)src;
}
Serializer &Serializer::operator=(const Serializer &src)
{
	(void)src;
	return *this;
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serializer(Data *ptr)
{
	uintptr_t result;
	result = reinterpret_cast< uintptr_t >(ptr);
	return result;
}

Data *Serializer::deserializer(uintptr_t raw)
{
	Data *result;
	result = reinterpret_cast< Data *>(raw);
	return result;
}