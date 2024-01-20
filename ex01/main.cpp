#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat b("LEE", 10);
	Form f1("42Seoul Subsidy Policy", 15, 15);
	Form f2("Survive Policy", 5, 5);

	f1.beSigned(b);
	b.signForm(f1);
	std::cout << b << std::endl;
	std::cout << f1 << std::endl;

	std::cout << std::endl;

	f2.beSigned(b);
	b.signForm(f2);
	std::cout << b << std::endl;
	std::cout << f2 << std::endl;
	return 0;
}