#include "./Zombie.hpp"

int main()
{
	Zombie *nuevaHorda = zombieHorde(6, "paco");
	nuevaHorda[2].announce();
	nuevaHorda[4].announce();
	nuevaHorda[1].announce();
	nuevaHorda[3].announce();
	delete[] nuevaHorda;
}