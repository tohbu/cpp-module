#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <stdint.h>

struct Data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &src);
	Serializer &operator=(const Serializer &src);
	~Serializer();

public:
	static uintptr_t serializer(Data *ptr);
	static Data *deserializer(uintptr_t raw);
};

#endif
