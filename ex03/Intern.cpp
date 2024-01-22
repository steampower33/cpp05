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

	int i;
	for (i = 0; i < 3; i++)
	{
		if (_target[i] == target)
			break ;
	}

	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << FormName << std::endl;
			return new ShrubberyCreationForm(FormName);
		case 1:
			std::cout << "Intern creates " << FormName << std::endl;
			return new RobotomyRequestForm(FormName);
		case 2:
			std::cout << "Intern creates " << FormName << std::endl;
			return new PresidentialPardonForm(FormName);
		default:
			throw Intern::DoesNotExistTarget();
	}
	return (NULL);
}