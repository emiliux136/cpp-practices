#pragma once
#include <cstddef>
#include <iostream>

template <typename E, typename F>
void iter(E *array, const size_t size, F function)
{
	if (!size || !array)
		return;
	for (size_t i = 0; i < size; i++)
		function(array[i]);
}

