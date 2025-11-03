#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include<string>



class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const std::string &type);
		Animal(const Animal& a);
		virtual ~Animal();
		Animal& operator=(const Animal& a);
		virtual  void makeSound()const;
		void setType(std::string type);
		std::string getType(void)const;
};
#endif