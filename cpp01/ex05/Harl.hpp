#ifndef HARL_HPP
#define HARL_HPP
#include<string>
#include <map>
#include <iostream>



class Harl
{
	private:
		void debug();
		void info();
		void warning();
		void error();		
		void (Harl::*_pFunc[4])(); 
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif