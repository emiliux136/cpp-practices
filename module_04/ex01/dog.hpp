#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *DogBrain;
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual ~Dog(); 
	void makeSound() const;
	void setIdea(std::string think);
	std::string getIdea(void); 
};

#endif