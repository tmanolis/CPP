#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/**
 * @brief Deleting a derived class object using a pointer of base class type 
 * that has a non-virtual destructor results in undefined behavior. 
 * To correct this situation, the base class should be defined with a virtual destructor. 
 * 
 * Useful link :
 * https://www.geeksforgeeks.org/virtual-destructor/
 */
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound(); // will output the dog sound!
	meta->makeSound(); // will output basic sound of Class Animal

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;
	
	// More Test than in the subject
	const WrongAnimal*	BadAnimal = new WrongCat();
	const WrongCat*		BadCat = new WrongCat();
	
	std::cout << std::endl << BadAnimal->getType() << " " << std::endl;
	std::cout << BadCat->getType() << " " << std::endl;
	BadAnimal->makeSound(); // will output WrongAnimal Sound
	BadCat->makeSound(); // will output WrongCat Sound

	delete BadAnimal;
	delete BadCat;

	return (0);
}