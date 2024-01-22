#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 72, 45), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {	
	static unsigned int seed;
	if (seed == 0)
	{
		seed = (unsigned int)time(NULL);
		srand(seed);
	}
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RobotomyRequestForm", 72 ,45), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other)
	{
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	checkForm(executor);
	std::cout << "DrrrrrrrrrrrrrrrrrrR" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully 50% of the time." << std::endl;
	else
		std::cout << _target << " failed to robotize." << std::endl;
}