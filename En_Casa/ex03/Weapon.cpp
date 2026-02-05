#include "Weapon.hpp"

Weapon::Weapon(std::string s)
{
    setType(s);
}

Weapon::~Weapon()
{}

const std::string& Weapon::getType() const
{
    return this->type;
}

void Weapon::setType(std::string s)
{
    this->type = s;
}
