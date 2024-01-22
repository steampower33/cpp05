#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
public:
	AForm(const std::string& name, int grade_sign, int grade_execute);
	AForm(const AForm& other);
	virtual ~AForm();
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
	class IsNotSignedException : public std::exception {
		public:
			const char* what() const throw();
	};
	virtual void execute(const Bureaucrat& executor) const = 0;
	void checkForm(const Bureaucrat& executor) const;
private:
	AForm();
	AForm& operator=(const AForm& other);
	const std::string _name;
	bool _sign;
	const int _grade_sign;
	const int _grade_execute;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif