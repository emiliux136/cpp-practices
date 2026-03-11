#include "Brain.hpp"

//Orthodox canonical form.

Brain::Brain()
{
	this->index = 0;
	std::cout << "Brain: Default constructor called\n";
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor called\n";
}

Brain::Brain(const Brain &other)
{	
	*this = other;
	std::cout << "Brain: Copy constructor called\n";
}

Brain &Brain::operator=(const Brain &other)
{
	for(int i = 0; i < 100; i++)
		idea[i] = other.idea[i];
	return *this;
	std::cout << "Brain: Copy constructor called\n";
}

void Brain::setIdea(std::string think)
{
	if(index < 100)
	{
		this->idea[index] = think;
		index++;
	}
}

std::string Brain::getIdea( void )
{
	std::string allIdeas = "";
	for(int i = 0; i < index && i < 100; i++)
	{
		allIdeas += this->idea[i];
		if(i < index - 1)
			allIdeas += "\n";
	}
	return allIdeas;
}