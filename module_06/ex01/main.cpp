#include "Serializer.hpp"

int main()
{
	Data *first = new Data;
	first->description = "The first list of this comprobation";
	first->number = 1;
	first->user = "emilgarc";

	Data *second = new Data;
	second->description = "blup blip blop";
	second->number = 2;
	second->user = "nobody";

	uintptr_t raw = Serializer::serialize(first);

	std::cout << "pointer: " << raw << std::endl;;
	std::cout << std::endl;

	Data *serialized = Serializer::deserialize(raw);

	std::cout << serialized->user << ", number: ";
	std::cout << serialized->number << std::endl;
	std::cout << serialized->description << std::endl;
	std::cout << std::endl;

	uintptr_t row = Serializer::serialize(second);
	Data *serialized_2 = Serializer::deserialize(row);

	std::cout << serialized_2->user << ", number: ";
	std::cout << serialized_2->number << std::endl;
	std::cout << serialized_2->description << std::endl;

	delete first;
	delete second;
	return(0);
}