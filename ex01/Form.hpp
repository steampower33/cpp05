#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
public:
	Form(const std::string& name, int grade_sign, int grade_execute);
	Form(const Form& other);
	~Form();
	std::string getName() const;
	bool getSign() const;
	int getGradeSign() const;
	int getGradeExecute() const;
	void beSigned(Bureaucrat& b);
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
private:
	Form();
	Form& operator=(const Form& other);
	const std::string _name;
	bool _sign;
	const int _grade_sign;
	const int _grade_execute;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif