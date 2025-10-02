/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:15:21 by likong            #+#    #+#             */
/*   Updated: 2025/10/01 13:15:21 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm();
		AForm(const std::string name, int gradeToSign, int gradeToExe, const std::string& target);
		AForm(const AForm& copy);
		virtual ~AForm();

		AForm& operator = (const AForm& copy);

		const std::string& getName() const;
		bool getIsSigned() const;

		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& bureau);

		const std::string& getTarget() const;

		void execute(const Bureaucrat& executor) const;
		virtual void executeThis() const = 0;

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

		class FormNotSignedException: public std::exception {
			public:
				FormNotSignedException(const std::string& message);
				const char* what() const noexcept override;
			private:
				const std::string _message;
		};
	
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExe;
		const std::string _target;
};

std::ostream& operator << (std::ostream& os, const AForm& aform);