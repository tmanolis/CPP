#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

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

	return (0);
}