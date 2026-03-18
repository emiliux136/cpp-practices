#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();
	
	virtual void makeSound() const = 0; 
	//Set this equal to zero makes it a pure virtual function, and any class that has at least one pure virtual function becomes abstract.
	virtual void setIdea(const std::string &think) const;
	virtual std::string getIdea() const;
	std::string getType() const;
};

#endif