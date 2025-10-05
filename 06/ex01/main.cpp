#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

#define BLUE "\033[34m"
#define WHITE "\033[0m"

int main(void)
{
	Data testData;

	testData.id = 0;
	testData.name = "first data";

	std::cout << "testData: " << &testData << std::endl;
	std::cout << "testData id: " << testData.id << std::endl;
	std::cout << "testData name: " << testData.name << std::endl;

	std::cout << BLUE << "\n----------Convert pointer to unsigned int----------\n\n" << WHITE;
	uintptr_t testSerialized = Serializer::serialize(&testData);
	std::cout << "testSerialize: " << testSerialized << std::endl;

	std::cout << BLUE << "\n----------Convert unsigned int to pointer----------\n\n" << WHITE;
	Data* testDeserialized = Serializer::deserialize(testSerialized);
	std::cout << "testDeserialized: " << testDeserialized << std::endl;
	std::cout << "testDeserialized id: " << testDeserialized->id << std::endl;
	std::cout << "testDeserialized name: " << testDeserialized->name << std::endl;

	std::cout << std::endl;
	if (testDeserialized == & testData)
		std::cout << BLUE << "Pointers are same."  << std::endl << WHITE;
	else
		std::cout << BLUE << "Pointers are not same."  << std::endl << WHITE;

	return (0);
}