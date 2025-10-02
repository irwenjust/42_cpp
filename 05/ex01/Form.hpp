/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:14:09 by likong            #+#    #+#             */
/*   Updated: 2025/10/01 13:14:10 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form();
		Form(const std::string name, int gradeToSign, int gradeToExe);
		Form(const Form& copy);
		~Form();

		Form& operator = (const Form& copy);

		const std::string& getName() const;
		bool getIsSigned() const;

		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& bureau);

		class GradeTooHighException: public std::exception {
			private:
				std::string _message;
			public:
				GradeTooHighException(const std::string& msg);
				const char* what() const noexcept override;
		};

		class GradeTooLowException: public std::exception {
			private:
				std::string _message;
			public:
				GradeTooLowException(const std::string& mag);
				const char* what() const noexcept override;
		};
	
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExe;
};

std::ostream& operator << (std::ostream& os, const Form& form);