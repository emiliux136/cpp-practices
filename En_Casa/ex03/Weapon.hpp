#ifndef VIOLENCE_CPP
# define VIOLENCE_CPP

#include <string>
#include <iostream>

class Weapon
{
private:
    std::string type;
public:
    Weapon(std::string s);
    ~Weapon();
    const std::string& getType() const;
    void setType(std::string s);
};

#endif