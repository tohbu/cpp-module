#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP
#include "Contact.hpp"
#define PHONE_BOOK_LEN 8

class PhoneBook
{
private:
	Contact _contacts[PHONE_BOOK_LEN];
	int _index;
	int _size;

public:
	PhoneBook(void);
	void print(void);
	void add(void);
	void search(void);
};

#endif
