#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	// Stack
	Zombie	ZombieStack("Come (Stack)");
	// Heap
	Zombie *ZombieHeap = newZombie("Pacome (heap)");

	ZombieStack.announce();
	ZombieHeap->announce();
	randomChump("Stoopido (Chump)");
	
	delete ZombieHeap;

	return (0);
}
