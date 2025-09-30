#pragma once

#include <string>
#include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string _name;
		int	_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();

		Bureaucrat& operator = (const Bureaucrat& copy);

		const std::string& getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(Form& form);

		class GradeTooHighException: public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException: public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

std::ostream& operator << (std::ostream& os, const Bureaucrat& bure);