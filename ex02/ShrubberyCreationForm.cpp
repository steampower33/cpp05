#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 145, 137), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

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
	try
	{
		if (this->getSign())
		{
			executor.signForm(*this);
			std::string newFilename = _target + "_shrubbery";
			// 파일 열기
			std::ofstream outputFile(newFilename);

			if (outputFile.is_open()) {
				// 아스키 트리 작성
				outputFile << "      *      \n";
				outputFile << "     ***     \n";
				outputFile << "    *****    \n";
				outputFile << "   *******   \n";
				outputFile << "  *********  \n";
				outputFile << " *********** \n";
				outputFile << "*************\n";
				outputFile << "     |||     \n";

				// 파일 닫기
				outputFile.close();
				std::cout << "The file was successfully created." << std::endl;
			} else {
				std::cerr << "파일을 열 수 없습니다." << std::endl;
			}
		}
		else
			throw AForm::IsNotSignedException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}