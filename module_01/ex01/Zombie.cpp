#include "./Zombie.hpp"

void Zombie::naming(const std::string &input)
{
	this->name = input;
	std::cout << "Zombie object " << this->name << " created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie object " << this->name << " destroyed" << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
