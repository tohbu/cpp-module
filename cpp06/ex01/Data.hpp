#ifndef DATA_HPP
#define DATA_HPP

struct Data
{
	int _value;

public:
	Data();
	Data(int value);
	Data(const Data &src);
	Data &operator=(const Data &src);
	~Data();
};

#endif