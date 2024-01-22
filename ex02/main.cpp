#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat b("LEE", 5);
	std::cout << b << std::endl;

	AForm* Shrubbery = new ShrubberyCreationForm("Shrubbery");
	AForm* Presidential = new PresidentialPardonForm("Presidential");

	std::cout << std::endl;

	b.signForm(*Shrubbery);
	b.executeForm(*Shrubbery);
	delete Shrubbery;

	std::cout << std::endl;

	AForm* Robotomy = new RobotomyRequestForm("Robotomy");
	b.signForm(*Robotomy);
	b.executeForm(*Robotomy);
	delete Robotomy;

	std::cout << std::endl;

	b.signForm(*Presidential);
	b.executeForm(*Presidential);
	delete Presidential;

	return 0;
}