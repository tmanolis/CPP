#include "Zombie.hpp"

Zombie*    zombieHorde(int N, std::string name);

int	main(void)
{
	int N = 5;

	Zombie	*ZombieHorde = zombieHorde(N, "Balthazar");

	for (int i = 0; i < N; i++)
		ZombieHorde[i].announce();
	delete [] ZombieHorde;

	return (0);
}
