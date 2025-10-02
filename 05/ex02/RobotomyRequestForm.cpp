/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:14:50 by likong            #+#    #+#             */
/*   Updated: 2025/10/01 13:14:51 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("Robotomy_Request_Form", 72, 45, "unknown"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("Robotomy_Request_Form", 72, 45, target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
: AForm(copy){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& copy) {
	if (this != &copy)
		AForm::operator=(copy);
	return *this;
}

void RobotomyRequestForm::executeThis() const {
	std::cout << "Some drilling noises" << std::endl;
	
	std::srand(std::time(0));
	bool isSuccess = std::rand() % 2;
	if (isSuccess)
		std::cout << this->getTarget() << " has been robotomized." << std::endl;
	else
		std::cout << this->getTarget() << " robotomy failed." << std::endl;
}
