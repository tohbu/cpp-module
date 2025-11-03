#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

 int main()
 {
	Animal *animals[10];
	for(int i = 0; i<10; i++)
	{	
		std::cout <<"	start" <<std::endl;
		if (i < 5)
			animals[i] = new Dog();
        else
			animals[i] = new Cat();
		std::cout <<"	end" <<std::endl;
	}
	for(int i = 0; i<10; i++)
		animals[i]->makeSound();
	for(int i = 0; i<10; i++)
	{
		std::cout <<"	start" <<std::endl;
		delete animals[i];
		std::cout <<"	end" <<std::endl;
	}
	Cat cat;
	Cat dcat = cat;
	Dog *dog = new Dog();
	Dog *ddog = new Dog(*dog);
	
	delete dog;
	delete ddog;
	return 0;	
 }