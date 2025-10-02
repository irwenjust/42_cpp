/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:15:18 by likong            #+#    #+#             */
/*   Updated: 2025/10/01 13:15:19 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("defaultAForm"), _isSigned(false), _gradeToSign(150), _gradeToExe(150),
_target("default_target") {}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExe, const std::string& target):
_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExe(gradeToExe), _target(target) {
	if (_gradeToSign < 1 || _gradeToExe < 1)
		throw GradeTooHighException("Grade is too high, failed to construct");
	if (_gradeToSign > 150 || _gradeToExe > 150)
		throw GradeTooLowException("Grade is too low, failed to construct");
}

AForm::AForm(const AForm& copy): _name(copy._name), _isSigned(copy._isSigned),
_gradeToSign(copy._gradeToSign), _gradeToExe(copy._gradeToExe), _target(copy._target) {}

AForm::~AForm() {}

AForm& AForm::operator = (const AForm& copy) {
	if (this != &copy)
		_isSigned = copy._isSigned;
	return *this;
}

const std::string& AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExe;
}

const std::string& AForm::getTarget() const {
	return _target;
}

void AForm::beSigned(const Bureaucrat& bureau) {
	if (bureau.getGrade() > _gradeToSign)
		throw GradeTooLowException("Grade is too low to sign");
	else
		_isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw FormNotSignedException("Form isn't sign yet");
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException("This executor's grade is too low, cannot be executed");
	this->executeThis();
}

AForm::GradeTooHighException::GradeTooHighException(const std::string& message): _message(message) {}

const char* AForm::GradeTooHighException::what() const noexcept {
	return _message.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& message)
: _message(message) {}

const char* AForm::GradeTooLowException::what() const noexcept {
	return _message.c_str();
}

AForm::FormNotSignedException::FormNotSignedException(const std::string& message): _message(message) {}

const char* AForm::FormNotSignedException::what() const noexcept {
	return _message.c_str();
}

std::ostream& operator << (std::ostream& os, const AForm& aform) {
	os << "AForm name: " << aform.getName()
		<< "\nIs Aform signed: " << aform.getIsSigned()
		<< "\nGrade to sign: " << aform.getGradeToSign()
		<< "\nGrade to execute: " << aform.getGradeToExecute()
		<< "\nTarget: " << aform.getTarget()
		<< std::endl;
	return (os);
}