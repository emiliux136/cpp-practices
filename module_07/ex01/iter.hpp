#include <iostream>

template <typename E> //Again E is a placeholder type

//third element is a pointer to a function that takes a E& and returns void
void iter(E &array, const size_t size, void (function)(E &))
{
    
}