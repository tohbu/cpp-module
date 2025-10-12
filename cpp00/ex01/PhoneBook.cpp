#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string> 
#include <cctype>
#include <cstdlib> 


bool is_digits(const std::string &str)
{
    if (str.empty())
        return false;
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
    {
        if (!std::isdigit(static_cast<unsigned char>(*it)))
            return false;
    }
    return true;
}

PhoneBook::PhoneBook(void)
{
	_index = 0;
	_size  = 0;
	return;
}

void PhoneBook::add(void)
{
	Contact NewContact;
	NewContact.read_input();
	if(_index  >= PHONE_BOOK_LEN )
		_index  -= PHONE_BOOK_LEN; 
	this->_contacts[_index++] = NewContact;
	if(_size < PHONE_BOOK_LEN)
		_size++;
	return;
}

void PhoneBook::print(void)
{
	for(int i = 0; i < _size; i++)
		this->_contacts[i].print(i);
}

void PhoneBook::search(void)
{
	std::string number;
	std::cout << "index>";
	getline(std::cin,number);
	if(std::cin.eof())
		throw std::runtime_error("EOF");
	if(!is_digits(number))
	{
		std::cout << "Invalid input please number\n";
		return;
	}		
	int i = std::atoi(number.c_str());
	if( i >= _size)
		std::cout << "Invalid index\n";
	else
		this->_contacts[i].print_all();
	return;
}
