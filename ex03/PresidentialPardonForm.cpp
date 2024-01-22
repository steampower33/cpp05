#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("", 25, 5), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm("PresidentialPardonForm", 25 ,5), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other)
	{
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	try
	{
		if (this->getSign())
		{
			executor.signForm(*this);
			std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		}
		else
			throw AForm::IsNotSignedException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}