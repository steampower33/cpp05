#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	Bureaucrat b("LEE", 1);
	AForm* ShrubberyCreationForm;
	AForm* RobotomyRequestForm;
	AForm* PresidentialPardonForm;
	Intern i;

	ShrubberyCreationForm = i.makeForm("Shrubbery", "ShrubberyCreation");
	RobotomyRequestForm = i.makeForm("Robotomy", "RobotomyRequest");
	PresidentialPardonForm = i.makeForm("Presidential", "PresidentialPardon");

	ShrubberyCreationForm->beSigned(b);
	ShrubberyCreationForm->execute(b);
	RobotomyRequestForm->beSigned(b);
	RobotomyRequestForm->execute(b);
	PresidentialPardonForm->beSigned(b);
	PresidentialPardonForm->execute(b);

	delete PresidentialPardonForm;
	delete RobotomyRequestForm;
	delete ShrubberyCreationForm;

	return 0;
}