#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 145, 137), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm("ShrubberyCreationForm", 145, 137), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
	{
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	checkForm(executor);
	std::string newFilename = _target + "_shrubbery";
	std::ofstream outputFile(newFilename.c_str());
	if (outputFile.is_open()) {
		outputFile << "      *      \n";
		outputFile << "     ***     \n";
		outputFile << "    *****    \n";
		outputFile << "   *******   \n";
		outputFile << "  *********  \n";
		outputFile << " *********** \n";
		outputFile << "*************\n";
		outputFile << "     |||     \n";
		outputFile.close();
		std::cout << "The file was successfully created." << std::endl;
	} else {
		std::cout << "The file does not open" << std::endl;
	}
}