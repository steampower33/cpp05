#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	if (this != &other)
	{
	}
	return *this;
}

Intern::~Intern() {}

const char* Intern::DoesNotExistTarget::what() const throw() {
	return "The Target Does not Exist.";
}

AForm* Intern::makeForm(const std::string FormName, const std::string target) {
	std::string _target[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	AForm* f;
	int i;
	for (i = 0; i < 3; i++)
	{
		if (_target[i] == target)
			break ;
	}

	switch (i)
	{
		case 0:
			f = new ShrubberyCreationForm(FormName);
			break;
		case 1:
			f = new RobotomyRequestForm(FormName);
			break;
		case 2:
			f = new PresidentialPardonForm(FormName);
			break;
		default:
			throw Intern::DoesNotExistTarget();
	}
	std::cout << "Intern creates " << FormName << std::endl;
	return (f);
}