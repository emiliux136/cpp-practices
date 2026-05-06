#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <exception>
# include <cstdlib>
# include <limits>
# include <string>
# include <cmath>

struct Data
{
	std::string user;
	int number;
	std::string description;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		// statics bc you dont need to create an object to use this metods, cant use this, ideal for a utility class.
};

#endif