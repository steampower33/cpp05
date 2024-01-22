#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat b("LEE", 10);
	std::cout << b << std::endl;

	std::cout << std::endl;

	Form f1("42Seoul Subsidy Policy", 15, 15);
	std::cout << f1 << std::endl;
	b.signForm(f1);
	std::cout << f1 << std::endl;

	std::cout << std::endl;

	Form f2("Survive Policy", 5, 5);
	std::cout << f2 << std::endl;
	b.signForm(f2);
	std::cout << f2 << std::endl;

	return 0;
}