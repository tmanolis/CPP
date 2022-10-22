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
	std::cout << " # --------------- Mandatory  ----------------- # " << std::endl;
	int	nb = 4;
	Animal	*AnimalArray[nb];

	for (int i = 0; i < nb; i++)
	{
		if (i % 2) // index 1 & 3
			AnimalArray[i] = new Cat();
		else
			AnimalArray[i] = new Dog();
		std::cout << std::endl << std::endl;
	}

	for (int i = 0; i < 4; i++)
	{
		AnimalArray[i]->makeSound();
		std::cout << std::endl;
	}

	for (int i = 0; i < nb; i++)
		delete AnimalArray[i];
	
	std::cout << std::endl << std::endl;
	std::cout << " # --------------- From example is the subject  ----------------- # " << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	delete j;	//should not create a leak
	delete i;

	std::cout << std::endl << std::endl;
	std::cout << " # --------------- Let's try and deep copy!  ----------------- # " << std::endl;
	
	Cat origin;
	std::cout << " # ~~~~~~~~~~~~~~~~~~~~~~ # " << std::endl;
	Cat copy(origin);
	std::cout << " # ~~~~~~~~~~~~~~~~~~~~~~ # " << std::endl;
	Cat assign;
	std::cout << " # ~~~~~~~~~~~~~~~~~~~~~~ # " << std::endl;
	assign = origin;
	std::cout << " # ~~~~~~~~~~~~~~~~~~~~~~ # " << std::endl;
	

	Cat *first = new Cat();
	Cat *second = new Cat(*first);

	delete first;
	delete second;

	return (0);
}