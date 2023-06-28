#ifndef INTERN_H
#define INTERN_H

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {
	public:
		Intern();
		Intern(Intern const &i);
		~Intern();

		Intern &operator=(Intern const &i);

		AForm *makeForm(std::string name, std::string target);
};

#endif