#include "Zombie.hpp"

void randomChump(std::string name)
{
	if (name.empty())
	{
		Zombie random("Empty");
		random.announce();
		return;
	}
	Zombie random(name);
	random.announce();
}
