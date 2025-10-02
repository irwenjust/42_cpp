/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:15:31 by likong            #+#    #+#             */
/*   Updated: 2025/10/01 13:15:31 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& copy);
		~Intern();

		Intern& operator = (const Intern& copy);

		AForm* makeForm(const std::string& name, const std::string& target);

        static AForm* makeShrubberyForm(const std::string& target);
        static AForm* makeRobotomyForm(const std::string& target);
        static AForm* makePresidentialForm(const std::string& target);

		class	FormNotFoundException : public std::exception {
			public:
				virtual const char* what() const noexcept override;
		};
};