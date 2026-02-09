#include "Zombie.hpp"

int main()
{
	Zombie *zombi = newZombie("");
	if (zombi)
	{
		zombi->announce();
		delete zombi;
	}
	randomChump(NULL);
	return (0);
}