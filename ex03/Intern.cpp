#include "Intern.hpp"

Intern::Intern() {return;}

Intern::Intern(Intern const &i)
{
	*this = i;
	return;
}

Intern::~Intern() {return;}

Intern &Intern::operator=(Intern const &i)
{
	(void)i;
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string list[3] = {"robotomy", "presidential", "shrubbery"};
	AForm		*forms[3] = {new RobotomyRequestForm(target), new PresidentialPardonForm(target), new ShrubberyCreationForm(target)};
	int			i;

	i = -1;
	while (++i < 3)
	{
		if (name == list[i])
		{
			std::cout << "Intern creates " << list[i] << std::endl;
			return (forms[i]);
		}
	}
	std::cout << name << ": no such a form exists" << std::endl;
	return (nullptr);	
}