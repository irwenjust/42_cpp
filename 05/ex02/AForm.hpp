#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool	_isSigned;
		const int	_gradeToSign;
		const int	_gradeToExe;

	public:
		AForm();
		AForm(const std::string name, int gradeToSign, int gradeToExe);
		AForm(const AForm& copy);
		~AForm();

		AForm& operator = (const AForm& copy);

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
};

std::ostream& operator << (std::ostream& os, const AForm& aform);