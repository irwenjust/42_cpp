#include "easyfind.hpp"

#include <iostream>
#include <array>
#include <deque>
#include <vector>
#include <list>

#define RED "\033[0;31m"
#define RESET "\033[0;0m"

static void	testArray();
static void	testVector();
static void	testDeque();
static void	testList();

// Testing for sequence containers which store data in the linear manner
int	main(void) {

	//Compilation failure triggered by static_assert (container's value type must be int)
	//std::array<float, 3>	arrFloat = {1.1f, 2.2f, 3.3f};
	//easyfind(arrFloat, 1.1f);
	
	testArray();
	testVector();
	testDeque();
	testList();

	return (0);
}

static void	testArray() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Container type: Array ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	std::array<int, 7>	arr = {-3, -2, -1, 0, 1, 2, 3};
	std::cout << "Array elements: ";
	for (std::array<int, 7>::iterator it = arr.begin(); it != arr.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
	try {
		std::cout << "Trying to access element '-1' (available): ";
		std::cout << *easyfind(arr, -1) << " found in the Array container" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try {
		std::cout << "Trying to access element '100' (unavailable): ";
		std::cout << *easyfind(arr, 100) << " found in the Arry container" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << "-----------------------------------------" << std::endl;

	std::array<int, 0>	arrEmpty = {};
	std::cout << "Array elements: ";
	if (arrEmpty.empty())
        std::cout << "(empty)";
    else {
		for (std::array<int, 0>::iterator it = arrEmpty.begin(); it != arrEmpty.end(); it++)
            std::cout << *it << " ";
    }
    std::cout << std::endl;
 	try {
		std::cout << "Trying to access element '0' (empty Array): ";
		std::cout << *easyfind(arrEmpty, 0) << " found in the Array container" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}


static void	testVector() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Container type: Vector ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	std::vector<int>	vec;
	for (int i = 0; i < 5; i++)
        vec.push_back(i);
    std::cout << "Vector elements: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
 	try {
		std::cout << "Trying to access element '2' (available): ";
		std::cout << *easyfind(vec, 2) << " found in the Vector container" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
 	try {
		std::cout << "Trying to access element '5' (unavailable): ";
		std::cout << *easyfind(vec, 5) << " found in the Vector container" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << "-----------------------------------------" << std::endl;

	std::vector<int>	vecEmpty = {};
	std::cout << "Vector elements: ";
	if (vecEmpty.empty())
        std::cout << "(empty)";
    else {
		for (std::vector<int>::iterator it = vecEmpty.begin(); it != vecEmpty.end(); it++)
            std::cout << *it << " ";
    }
    std::cout << std::endl;
 	try {
		std::cout << "Trying to access element '2' (empty Vector): ";
		std::cout << *easyfind(vecEmpty, 2) << " found in the Vector container" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

static void	testDeque() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Container type: Deque ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	std::deque<int>	deq;
	for (int i = 0; i < 5; i++)
        deq.push_back(i);
	for (int i = 0; i < 5; i++)
		deq.push_front(i);
    std::cout << "Deque elements: ";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
 	try {
		std::cout << "Trying to access element '0' (available): ";
		std::cout << *easyfind(deq, 0) << " found in the Vector container" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
 	try {
		std::cout << "Trying to access element '5' (unavailable): ";
		std::cout << *easyfind(deq, 5) << " found in the Vector container" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << "-----------------------------------------" << std::endl;
	
	std::deque<int>	deqEmpty = {};
	std::cout << "Deque elements: ";
	if (deqEmpty.empty())
        std::cout << "(empty)";
    else {
		for (std::deque<int>::iterator it = deqEmpty.begin(); it != deqEmpty.end(); it++)
            std::cout << *it << " ";
    }
    std::cout << std::endl;
 	try {
		std::cout << "Trying to access element '100' (empty Deque): ";
		std::cout << *easyfind(deqEmpty, 100) << " found in the Deque container" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

static void	testList() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Container type: List ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	std::list<int>	lst;
	for (int i = 0; i < 5; i++)
        lst.push_back(100);
    std::cout << "List elements: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
 	try {
		std::cout << "Trying to access element '100' (available): ";
		std::cout << *easyfind(lst, 100) << " found in the List container" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
 	}
	try {
		std::cout << "Trying to access element '1' (unavailable): ";
		std::cout << *easyfind(lst, 1) << " found in the List container" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << "-----------------------------------------" << std::endl;
	
	std::list<int>	lstEmpty = {};
	std::cout << "List elements: ";
	if (lstEmpty.empty())
        std::cout << "(empty)";
    else {
		for (std::list<int>::iterator it = lstEmpty.begin(); it != lstEmpty.end(); it++)
            std::cout << *it << " ";
    }
    std::cout << std::endl;
 	try {
		std::cout << "Trying to access element '100' (empty List): ";
		std::cout << *easyfind(lstEmpty, 100) << " found in the List container" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << "-----------------------------------------" << std::endl;
}
