#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name(""), _sign(false), _grade_sign(1), _grade_execute(1) {}

AForm::AForm(const std::string& name, int grade_sign, int grade_execute)
: _name(name), _sign(false), _grade_sign(grade_sign), _grade_execute(grade_execute) {
	if (_grade_sign < 1)
		throw GradeTooHighException();
	else if (_grade_sign > 150)
		throw GradeTooLowException();
	if (_grade_execute < 1)
		throw GradeTooHighException();
	else if (_grade_execute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
: _name(other._name), _sign(other._sign),
_grade_sign(other._grade_sign), _grade_execute(other._grade_execute) { }

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
	{
		_sign = other._sign;
	}
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getSign() const {
	return _sign;
}

int AForm::getGradeSign() const {
	return _grade_sign;
}

int AForm::getGradeExecute() const {
	return _grade_execute;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Form Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Form Grade Too Low";
}

const char* AForm::IsNotSignedException::what() const throw() {
	return "Form is Not Signed";
}

void AForm::beSigned(Bureaucrat& b) {
	if (b.getGrade() <= _grade_sign)
		_sign = true;
	else
		throw GradeTooLowException();
}

void AForm::checkForm(const Bureaucrat& executor) const {
	if (_sign == false)
		throw IsNotSignedException();
	if (executor.getGrade() > _grade_execute)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << f.getName() << ", sign "
	<< f.getSign() << ", grade sign "
	<< f.getGradeSign() << ", grade execute "
	<< f.getGradeExecute() << ".";
	return os;
}
