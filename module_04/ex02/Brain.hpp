#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

/*We use mutable when we want some variables to be modifiable even when accessed
 through a const reference/pointer to an object.*/

class Brain
{
protected:
	mutable std::string idea[100];
	mutable int index;
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	virtual ~Brain();
	void setIdea(std::string think) const;
	std::string getIdea( void ) const;
};

#endif