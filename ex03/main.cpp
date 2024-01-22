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

	std::cout << std::endl;

	b.signForm(*ShrubberyCreationForm);
	b.executeForm(*ShrubberyCreationForm);

	std::cout << std::endl;

	b.signForm(*RobotomyRequestForm);
	b.executeForm(*RobotomyRequestForm);

	std::cout << std::endl;

	b.signForm(*PresidentialPardonForm);
	b.executeForm(*PresidentialPardonForm);

	std::cout << std::endl;

	delete PresidentialPardonForm;
	delete RobotomyRequestForm;
	delete ShrubberyCreationForm;

	return 0;
}