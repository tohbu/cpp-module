#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

 int main()
 {
	Cat cat;
	Cat dcat = cat;
	Dog *dog = new Dog();
	Dog *ddog = new Dog(*dog);
	cat.makeSound();
	dog->makeSound();
	// Animal a = Animal();
	delete dog;
	delete ddog;
	return 0;	
 }