#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	if (name.empty())
	{
		Zombie *Class = new Zombie("Empty");
		return Class;
	}
	Zombie *Class = new Zombie(name);
	return Class;
}
