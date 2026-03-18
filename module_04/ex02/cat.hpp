#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *catBrain;
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual ~Cat(); 
	
	void makeSound() const;
	void setIdea(const std::string &think) const;
	std::string getIdea() const;
};

/*Animal needs a virtual destructor so deleting a Dog/Cat through an Animal* calls the derived destructor too.
Without it, only the base destructor may run (undefined behavior), causing skipped cleanup and possible memory leaks (e.g., Brain in Dog/Cat).*/

#endif