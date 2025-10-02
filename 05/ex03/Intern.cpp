/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:15:28 by likong            #+#    #+#             */
/*   Updated: 2025/10/01 13:15:29 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& copy) {
    (void)copy;
}

Intern::~Intern(){}

Intern& Intern::operator = (const Intern& copy) {
    (void)copy;
    return (*this);
}

AForm* Intern::makeShrubberyForm(const std::string& target) {
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyForm(const std::string& target) {
    return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidentialForm(const std::string& target) {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
    std::string typeForm[3] = {"shrubbery", "robotomy", "presidential"};

    AForm* (*formFunc[3])(const std::string& target) = {&Intern::makeShrubberyForm, &Intern::makeRobotomyForm, &Intern::makePresidentialForm};

    for (int i = 0; i < 3; i++) {
        if (name == typeForm[i]) {
            std::cout << "Intern creates " << typeForm[i] << std::endl;
            return (formFunc[i](target));
        }
    }
    throw Intern::FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const noexcept {
    return ("Invalid form type, can't create that form.");
}
