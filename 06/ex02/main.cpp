/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:15:53 by likong            #+#    #+#             */
/*   Updated: 2025/10/06 11:15:53 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime> //std::time
#include "Base.hpp"
#include "Identify.hpp"

int main(void)
{
	std::srand(std::time(0));
	for (int i = 0; i < 6; i++)
	{
		std::cout << "\n---Test: " << i + 1 << "---\n\n";
		Base* testBase = generate();
		std::cout << "Identify ptr: ";
		identify(testBase);
		std::cout << "Identify ref: ";
		identify(*testBase);
		delete testBase;
		testBase = nullptr;
	}
	return (0);
}