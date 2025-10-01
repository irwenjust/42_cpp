#include "AForm.hpp"

AForm::AForm(): _name("defaultAForm"), _isSigned(false), _gradeToSign(150), _gradeToExe(150) {}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExe): _name(name),
_isSigned(false), _gradeToSign(gradeToSign), _gradeToExe(gradeToExe) {
	if (_gradeToSign < 1 || _gradeToExe < 1)
		throw GradeTooHighException("Grade is too high, failed to construct");
	if (_gradeToSign > 150 || _gradeToExe > 150)
		throw GradeTooLowException("Grade is too low, failed to construct");
}

AForm::AForm(const AForm& copy): _name(copy._name), _isSigned(copy._isSigned),
_gradeToSign(copy._gradeToSign), _gradeToExe(copy._gradeToExe) {}

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

void AForm::beSigned(const Bureaucrat& bureau) {
	if (bureau.getGrade() > _gradeToSign)
		throw GradeTooLowException("Grade is too low to sign");
	else
		_isSigned = true;
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

std::ostream& operator << (std::ostream& os, const AForm& Aform) {
	os << "AForm name: " << Aform.getName()
		<< "\nIs Aform signed: " << Aform.getIsSigned()
		<< "\nGrade to sign: " << Aform.getGradeToSign()
		<< "\nGrade to execute: " << Aform.getGradeToExecute()
		<< std::endl;
	return (os);
}