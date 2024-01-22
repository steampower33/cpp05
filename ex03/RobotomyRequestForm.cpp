#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 72, 45), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

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
	try
	{
		if (!this->getSign())
			throw AForm::IsNotSignedException();
		if (!(executor.getGrade() <= this->getGradeExecute()))
			throw AForm::GradeTooLowException();
		executor.signForm(*this);
		std::cout << "DrrrrrrrrrrrrrrrrrrR" << std::endl;
		// seed 값으로 현재시간 부여
		srand((unsigned int)time(NULL));
		if (rand() % 2 == 0)
			std::cout << _target << " has been robotomized successfully 50% of the time." << std::endl;
		else
			std::cout << _target << " failed to robotize." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}