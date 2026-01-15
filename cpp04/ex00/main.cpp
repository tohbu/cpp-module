#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();	 //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete j;
	delete i;
	delete meta;
	std::cout << "\n	Wrong animal" << std::endl;
	const WrongAnimal *w_meta = new WrongAnimal();
	const WrongAnimal *w_j = new WrongDog();
	const WrongAnimal *w_i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	w_i->makeSound();  //will output the cat sound!
	w_j->makeSound();
	w_meta->makeSound();

	delete w_j;
	delete w_i;
	delete w_meta;

	return 0;
}