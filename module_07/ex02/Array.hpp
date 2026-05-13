#pragma once
#include <iostream>

template <typename T>

class Array
{
	private:
		T *array;
		unsigned int siz;
	public:
	
	unsigned int size() const
		{
			return(this->siz);
		}

		Array() : siz(0) 
		{
			std::cout << "Default Constructor called: Empty Array of 0 size created." << std::endl;
			this->array = new T[this->siz];
		}

		Array(unsigned int n) : siz(n)
		{
			std::cout << "Constructor called: Empty Array of " << n << " size created." << std::endl;
			this->array = new T[this->siz];
		}

		Array(const Array &other) : siz(other.size())
		{
			std::cout << "Copy constructor called." << std::endl;
			this->array = NULL;
			*this = other;
		}

		Array &operator=(const Array &other)
		{
			std::cout << "Copy assigment operator called." << std::endl;
			if(this->array != NULL)
				delete[] this->array;
			if(other.size() != 0)
			{
				this->siz = other.size();
				this->array = new T[this->siz];
				for(unsigned int i = 0; i < this->siz; i++)
					this->array[i] = other.array[i];
			}
			return (*this);
		}

		T &operator[](unsigned int i)
		{
			if(i >= this->siz || this->array == NULL)
			{
				throw Array<T>::IndexOutBounds();
			}
			return(this->array[i]);
		}

		// delete[] is used to free up memory dynamically allocated to an array using new[].
		~Array()
		{
			std::cout << "Destructor called." << std::endl;
			if(this->array != NULL)
				delete[] this->array;
		}

		class IndexOutBounds : public std::exception
		{
			public:
			const char* what() const noexcept override 
			{
				return "The value of this index is out of bounds";
			}
		};
};