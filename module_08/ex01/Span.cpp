#include "Span.hpp"
#include <random>

 // reserve() is used with containers like std::vector and std::string to pre-allocate memory capacity without changing the container’s size.
Span::Span(unsigned int N): size(N), pos(0)
{
	//std::cout << "Span constructor of " << N << " size called." << std::endl;
	this->storage.reserve(this->getSize());
}

Span::Span(const Span &other): size(other.getSize()), pos(other.getPos())
{
	//std::cout << "Span Copy Constructor called" << std::endl;
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	//std::cout << "Span Assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	this->size = other.getSize();
	this->pos = other.getPos();
	this->storage = other.storage;
	return *this;
}

Span::~Span(){}

std::vector<int> generate_random_list(size_t n, int minv, int maxv)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(minv, maxv);

	std::vector<int> v;
	v.reserve(n);
	for (size_t i = 0; i < n; ++i)
		v.push_back(dist(gen));
	return v;
}

unsigned int Span::shortestSpan()
{
	if(this->storage.size() < 2)
		throw OnlyOneNumber();
	std::vector<int> tmp = this->storage;
	std::sort(tmp.begin(), tmp.end());
	int shortest = tmp[1] - tmp[0];
	int i = 1;
	while(i < tmp.size())
	{
		if(tmp[i] - tmp[i - 1] < shortest)
			shortest = tmp[i] - tmp[i - 1];
		i++;
	}
	return (shortest);
}

unsigned int Span::longestSpan()
{
	if(this->storage.size() < 2)
		throw OnlyOneNumber();
	std::vector<int> tmp = this->storage;
	std::sort(tmp.begin(), tmp.end());
	int longest = tmp[tmp.size() - 1] - tmp[0];
	return (longest);
}


void Span::addNumber(unsigned int N)
{
	if(this->storage.size() == size)
		throw FulledVector();
	this->pos++;
	this->storage.push_back(N);
}

//has to be declared as const in order to include them into the copy constructor
unsigned int Span::getSize() const
{
	return(this->size);
}

unsigned int Span::getPos() const
{
	return(this->pos);
}