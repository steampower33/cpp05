#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	class DoesNotExistTarget : public std::exception {
		public:
			const char* what() const throw();
	};
	AForm* makeForm(const std::string FormName, const std::string target);
};

#endif