/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:18:03 by likong            #+#    #+#             */
/*   Updated: 2025/10/16 12:18:04 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int	main(void) {
    std::cout << "\n----------Mstack Test----------\n\n";
	MutantStack<int> mstack;

	std::cout << "\n---add two elements---\n\n";
	mstack.push(5);
	mstack.push(17);
	std::cout  << "the top element is: " << mstack.top() << std::endl;
	std::cout  << "the mstack size is: " << mstack.size() << std::endl;

	std::cout << "\n---delete the top element---\n\n";
	mstack.pop();
	std::cout  << "the top element is: " << mstack.top() << std::endl;
	std::cout  << "the mstack size is: " << mstack.size() << std::endl;

	std::cout << "\n---add more elements and test iterator---\n\n";
	mstack.push(3);
	mstack.push(6);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout  << "the it element is: ";
	std::cout << *it << std::endl; //begin is the first element
	std::cout  << "move down it: ";
	++it;
	std::cout << *it << std::endl;
	std::cout  << "move up it: ";
	--it;
	std::cout << *it << std::endl;

	std::cout  << "the ite element is: ";
	--ite; //end is the position after last elements
	std::cout << *ite << std::endl;
	std::cout  << "move up ite: ";
	--ite;
	std::cout << *ite << std::endl;
	std::cout  << "move down ite: ";
	++ite;
	std::cout << *ite << std::endl;
	++ite; //put ite back to the end position

	std::cout << "\n---print all elements with it---\n\n";
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\n---print all elements with ite---\n\n";
	it = mstack.begin();
	while (ite != it) {
		--ite;
		std::cout << *ite << std::endl;
	}
	
	std::cout << "\n---Compare with normal stack---\n\n";
	std::stack<int> s(mstack);
	while (!s.empty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}

	std::cout << "\n----------Compare with list----------\n\n";
	std::list<int> lst;

	std::cout << "\n---add two elements---\n\n";
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "the top element is: " << lst.back() << std::endl;
	std::cout << "the list size is: " << lst.size() << std::endl;

	std::cout << "\n---delete the top element---\n\n";
	lst.pop_back();
	std::cout << "the top element is: " << lst.back() << std::endl;
	std::cout << "the list size is: " << lst.size() << std::endl;

	std::cout << "\n---add more elements and test iterator---\n\n";
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator itLst = lst.begin();
	std::list<int>::iterator iteLst = lst.end();

	std::cout << "the itLst element is: ";
	std::cout << *itLst << std::endl;
	std::cout << "move down itLst: ";
	++itLst;
	std::cout << *itLst << std::endl;
	std::cout << "move up itLst: ";
	--itLst;
	std::cout << *itLst << std::endl;

	std::cout << "the iteLst element is: ";
	--iteLst;
	std::cout << *iteLst << std::endl;
	std::cout << "move up ite: ";
	--iteLst;
	std::cout << *iteLst << std::endl;
	std::cout << "move down ite: ";
	++iteLst;
	std::cout << *iteLst << std::endl;
	++iteLst;

	std::cout<< "\n---print all elements with itLst---\n\n";
	while (itLst != iteLst) {
		std::cout << *itLst << std::endl;
		++itLst;
	}

	std::cout<< "\n---print all elements with iteLst---\n\n";
	itLst = lst.begin();
	while (iteLst != itLst) {
		--iteLst;
		std::cout << *iteLst << std::endl;
	}

	return (0);
}
