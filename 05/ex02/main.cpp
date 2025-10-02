/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:14:42 by likong            #+#    #+#             */
/*   Updated: 2025/10/01 13:14:42 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::cout << "\n---Constructor Test---\n\n";
	ShrubberyCreationForm shrub;
	RobotomyRequestForm robot;
	PresidentialPardonForm presi;

	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << presi << std::endl;

	std::cout << "\n----------Shrubbery Test----------\n\n";
	try	{
		std::cout << "\n---Create Executors---\n\n";
		Bureaucrat	manager("manager", 5);
		Bureaucrat	intern("intern", 150);
		std::cout << manager << std::endl;
		std::cout << intern << std::endl;

		std::cout << "\n---Create ShrubberyCreationForm---\n\n";
		ShrubberyCreationForm shrubForm("shrubForm");
		std::cout << shrubForm << std::endl;

		std::cout << "\n---Execute Unsigned Form---\n";
		intern.executeForm(shrubForm);
		manager.executeForm(shrubForm);

		std::cout << "\n---Sign the Form---\n";
		intern.signForm(shrubForm);
		manager.signForm(shrubForm);
		std::cout << std::endl << shrubForm << std::endl;

		std::cout << "\n---Execute Signed Form---\n";
		intern.executeForm(shrubForm);
		manager.executeForm(shrubForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n----------Robotomy Testing----------\n\n";
	try	{
		std::cout << "\n---Create Executors---\n\n";
		Bureaucrat	manager("manager", 5);
		Bureaucrat	intern("intern", 150);
		std::cout << manager << std::endl;
		std::cout << intern << std::endl;

		std::cout << "\n---Create RobotomyRequestForm---\n\n";
		RobotomyRequestForm robotForm("robotForm");
		std::cout << robotForm << std::endl;

		std::cout << "\n---Execute Unsigned Form---\n";
		intern.executeForm(robotForm);
		manager.executeForm(robotForm);

		std::cout << "\n---Sign the Form---\n";
		intern.signForm(robotForm);
		manager.signForm(robotForm);
		std::cout << std::endl << robotForm << std::endl;

		std::cout << "\n---Execute Signed Form---\n";
		intern.executeForm(robotForm);
		manager.executeForm(robotForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n----------President Testing----------\n\n";
	try	{
		std::cout << "\n---Create Executors---\n\n";
		Bureaucrat	manager("manager", 5);
		Bureaucrat	intern("intern", 150);
		std::cout << manager << std::endl;
		std::cout << intern << std::endl;

		std::cout << "\n---Create PresidentialPardonForm---\n\n";
		PresidentialPardonForm presForm("presForm");
		std::cout << presForm << std::endl;

		std::cout << "\n---Execute Unsigned Form---\n";
		intern.executeForm(presForm);
		manager.executeForm(presForm);

		std::cout << "\n---Sign the Form---\n";
		intern.executeForm(presForm);
		manager.signForm(presForm);
		std::cout << std::endl << presForm << std::endl;

		std::cout << "\n---Execute Signed Form---\n";
		intern.executeForm(presForm);
		manager.executeForm(presForm);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return 0;
}