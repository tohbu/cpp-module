#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

int main()
{
	PhoneBook MyPhoneBook;
		try
		{
			while(1)
			{
				std::string cmd;
				std::cout << "PhoneBook>";
				if(!getline(std::cin,cmd))
					throw std::runtime_error("EOF");		
				if(cmd == "ADD")
					MyPhoneBook.add();
				else if(cmd =="SEARCH")
				{
					MyPhoneBook.print();
					MyPhoneBook.search();
				}
				else if( cmd == "EXIT")
					return 0;		
			}
		}
		catch(const std::runtime_error& e)
		{
			std::cerr << "\n[Exception] " << e.what() << '\n';
			return 1;
		}	
}