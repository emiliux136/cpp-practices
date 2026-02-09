#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
{
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB()
{}

void HumanB::setWeapon(Weapon& w)
{
    weapon = &w;
}

void HumanB::attack() const 
{
    if (HumanB::weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " doesn't have a weapon to attack with" << std::endl;
}