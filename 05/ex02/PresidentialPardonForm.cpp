/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:14:45 by likong            #+#    #+#             */
/*   Updated: 2025/10/01 13:14:46 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("Presidential_Pardon_Form", 25, 5, "unknown"){}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("Presidential_Pardon_Form", 25, 5, target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
: AForm(copy){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& copy) {
	if (this != &copy)
		AForm::operator=(copy);
	return *this;
}

void PresidentialPardonForm::executeThis() const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
