#include "Zombie.hpp"

Zombie*    zombieHorde(int N, std::string name)
{
	Zombie	*ZombieHorde = new Zombie[N];

	for (int i = 0; i < N; i++)
		ZombieHorde[i].setName(name);
	return (ZombieHorde);
}