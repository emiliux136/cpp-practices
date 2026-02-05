#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(const std::string& n, Weapon& w) : name(n), weapon(w) 
{}

HumanA::~HumanA()
{}

void HumanA::setName(std::string s)
{
    this->name = s;
}

std::string HumanA::getName()
{
    return this->name;
}

void HumanA::attack() const 
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}