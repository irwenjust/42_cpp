/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:15:34 by likong            #+#    #+#             */
/*   Updated: 2025/10/01 13:15:34 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AForm.hpp"
#include "Intern.hpp"

int main() {
	Intern intern;

	std::cout << "\n----------Normal Test----------\n\n";
	try	{
		AForm* shrub = intern.makeForm("shrubbery", "shrubForm");
		std::cout << std::endl << *shrub << std::endl;
		delete shrub;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	try	{
		AForm* robot = intern.makeForm("robotomy", "robotForm");
		std::cout << std::endl << *robot << std::endl;
		delete robot;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try	{
		AForm* pres = intern.makeForm("presidential", "presForm");
		std::cout << std::endl << *pres << std::endl;
		delete pres;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n----------Invalid Test----------\n\n";

	try	{
		AForm* invalidType = intern.makeForm("nothing", "presForm");
		std::cout << std::endl << *invalidType << std::endl;
		delete invalidType;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try	{
		AForm* noType = intern.makeForm("", "presForm");
		std::cout << std::endl << *noType << std::endl;
		delete noType;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try	{
		AForm* noTarget = intern.makeForm("presidential", "");
		std::cout << std::endl << *noTarget<< std::endl;
		delete noTarget;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return 0;
}