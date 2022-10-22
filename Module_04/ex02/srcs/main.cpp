#include "AAnimal.hpp"
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
	AAnimal	*AAnimalArray[nb];

	for (int i = 0; i < nb; i++)
	{
		if (i % 2) // index 1 & 3
			AAnimalArray[i] = new Cat();
		else
			AAnimalArray[i] = new Dog();
		std::cout << std::endl << std::endl;
	}

	std::cout << "Should sound like a cat : ";
	AAnimalArray[1]->makeSound();
	std::cout << "Should sound like a dog : ";
	AAnimalArray[0]->makeSound();
	std::cout << std::endl << std::endl;

	for (int i = 0; i < nb; i++)
		delete AAnimalArray[i];
	

	// std::cout << " # --------------- Test for AAnimal is an abstract Class  ----------------- # " << std::endl;
	
	// AAnimal	Test;

	return (0);
}