#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat b("LEE", 1);
	std::cout << b << std::endl;

	std::cout << std::endl;

	// AForm* error = new ShrubberyCreationForm();
	AForm* Shrubbery = new ShrubberyCreationForm("shrubbery");
	std::cout << *Shrubbery << std::endl;
	Shrubbery->execute(b);
	Shrubbery->beSigned(b);
	std::cout << *Shrubbery << std::endl;
	Shrubbery->execute(b);

	std::cout << std::endl;

	AForm* Robotomy = new RobotomyRequestForm("robotomy");
	std::cout << *Robotomy << std::endl;
	Robotomy->execute(b);
	Robotomy->beSigned(b);
	std::cout << *Robotomy << std::endl;
	Robotomy->execute(b);

	std::cout << std::endl;

	AForm* Presidential = new PresidentialPardonForm("Presidential");
	std::cout << *Presidential << std::endl;
	Presidential->execute(b);
	Presidential->beSigned(b);
	std::cout << *Presidential << std::endl;
	Presidential->execute(b);

	std::cout << std::endl;

	delete Shrubbery;
	delete Robotomy;
	delete Presidential;
	return 0;
}