#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nick_name;
		std::string _phone_number;
		std::string _darkest;
	public:
		Contact();
		void print(int index);
		void print_all();
		void read_input();
};
#endif

