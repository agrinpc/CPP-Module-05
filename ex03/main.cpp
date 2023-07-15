#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat bureaucrat("Evaluator", 10);
	Intern					i;
	AForm					*f1 = i.makeForm("robotomy", "Scholarship");
	AForm					*f2 = i.makeForm("presidential", "Milad");
	AForm					*f3 = i.makeForm("shrubbery", "42Heilbronn");
	AForm					*f4 = i.makeForm("wrong_form", "wrong_target");

	std::cout << std::endl;
	if (f1)
	{
		bureaucrat.signForm(*f1);
		bureaucrat.executeForm(*f1);
		std::cout << std::endl;
	}
	if (f2)
	{
		bureaucrat.signForm(*f2);
		bureaucrat.executeForm(*f2);
		std::cout << std::endl;
	}
	if (f3)
	{
		bureaucrat.signForm(*f3);
		bureaucrat.executeForm(*f3);
		std::cout << std::endl;
	}
	if (f4)
	{
		bureaucrat.signForm(*f3);
		bureaucrat.executeForm(*f3);
		std::cout << std::endl;
	}
    return (0);
}