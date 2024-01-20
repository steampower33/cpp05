#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : _target(other._target) {}

ShrubberyCreationForm::ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
	{
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}