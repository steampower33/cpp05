#include "Bureaucrat.hpp"

int main() {
	try
	{
		try
		{
			Bureaucrat a("a", 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		Bureaucrat a("a", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat a("a", 1);
	Bureaucrat b("b", 150);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	try
	{
		a.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		b.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}