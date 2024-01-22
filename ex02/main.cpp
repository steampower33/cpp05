#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat b("LEE", 10);
	std::cout << b << std::endl;

	std::cout << std::endl;

	AForm* ShrubberyForm = new ShrubberyCreationForm("shrubbery");
	std::cout << *ShrubberyForm << std::endl;
	ShrubberyForm->execute(b);
	ShrubberyForm->beSigned(b);
	std::cout << *ShrubberyForm << std::endl;
	ShrubberyForm->execute(b);

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
	return 0;
}