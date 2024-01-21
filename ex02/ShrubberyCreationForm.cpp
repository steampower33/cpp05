#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm::ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
	{
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::beSigned(const Bureaucrat& b) {
	try
	{
		if (b.getGrade() <= _grade_sign)
		{
			std::string newFilename =  _target + "_shrubbery";

			// 파일 열기
			std::ofstream outputFile(newFilename);

			if (outputFile.is_open()) {
				// 아스키 트리 작성
				outputFile << "	     *      \n";
				outputFile << "     ***     \n";
				outputFile << "    *****    \n";
				outputFile << "   *******   \n";
				outputFile << "  *********  \n";
				outputFile << " *********** \n";
				outputFile << "*************\n";
				outputFile << "     |||     \n";

				// 파일 닫기
				outputFile.close();
			} else {
				std::cerr << "파일을 열 수 없습니다." << std::endl;
			}
		}
		else
			throw 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}