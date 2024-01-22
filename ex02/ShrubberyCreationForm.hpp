#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "fstream"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();
	void execute(const Bureaucrat& executor) const;
private:
	ShrubberyCreationForm();
	std::string _target;
};

#endif