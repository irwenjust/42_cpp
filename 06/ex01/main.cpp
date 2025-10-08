/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:15:27 by likong            #+#    #+#             */
/*   Updated: 2025/10/06 11:15:28 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data testData;

	testData.id = 0;
	testData.name = "first data";

	std::cout << "testData: " << &testData << std::endl;
	std::cout << "testData id: " << testData.id << std::endl;
	std::cout << "testData name: " << testData.name << std::endl;

	std::cout << "\n----------Convert pointer to unsigned int----------\n\n";
	uintptr_t testSerialized = Serializer::serialize(&testData);
	std::cout << "testSerialize: " << testSerialized << std::endl;

	std::cout << "\n----------Convert unsigned int to pointer----------\n\n";
	Data* testDeserialized = Serializer::deserialize(testSerialized);
	std::cout << "testDeserialized: " << testDeserialized << std::endl;
	std::cout << "testDeserialized id: " << testDeserialized->id << std::endl;
	std::cout << "testDeserialized name: " << testDeserialized->name << std::endl;

	std::cout << std::endl;
	if (testDeserialized == & testData)
		std::cout << "Pointers are same."  << std::endl;
	else
		std::cout << "Pointers are not same."  << std::endl;

	return (0);
}