#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
protected:
	std::string idea[100];
	int index;
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	virtual ~Brain();
	void setIdea(std::string think);
	std::string getIdea( void );
};

#endif