#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int	main(void)
{
	Bureaucrat bureaucrat("Evaluator", 6);
	PresidentialPardonForm	f1("Milad");
	ShrubberyCreationForm	f2("42Heilbronn");
	RobotomyRequestForm		f3("Scholarship Form");

	bureaucrat.signForm(f1);
	bureaucrat.executeForm(f1);
	std::cout << std::endl;
	bureaucrat.signForm(f2);
	bureaucrat.executeForm(f2);
	std::cout << std::endl;
	bureaucrat.signForm(f3);
	bureaucrat.executeForm(f3);
    return (0);
}