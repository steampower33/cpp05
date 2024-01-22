#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name(""), _sign(false), _grade_sign(1), _grade_execute(1) {}

Form::Form(const std::string& name, int grade_sign, int grade_execute)
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

Form::Form(const Form& other)
: _name(other._name), _sign(other._sign),
_grade_sign(other._grade_sign), _grade_execute(other._grade_execute) { }

Form& Form::operator=(const Form& other) {
	if (this != &other)
	{
		_sign = other._sign;
	}
	return *this;
}

Form::~Form() {}

std::string Form::getName() const {
	return _name;
}

bool Form::getSign() const {
	return _sign;
}

int Form::getGradeSign() const {
	return _grade_sign;
}

int Form::getGradeExecute() const {
	return _grade_execute;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade Too High";
}
const char* Form::GradeTooLowException::what() const throw() {
	return "Grade Too Low";
}

void Form::beSigned(Bureaucrat& b) {
	if (b.getGrade() <= _grade_sign)
		_sign = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << f.getName() << ", sign "
	<< f.getSign() << ", grade sign "
	<< f.getGradeSign() << ", grade execute "
	<< f.getGradeExecute() << ".";
	return os;
}
