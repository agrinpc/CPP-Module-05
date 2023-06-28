#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :  AForm("Pardon_Form", 25, 5), _target("No Target") {return ;}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Pardon_Form", 25, 5), _target(target) {return;}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& c) : AForm(c), _target( c._target) {return;}

PresidentialPardonForm::~PresidentialPardonForm() {return;}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &c)
{
    if (this != &c)
		this->_target = c._target;
	return (*this);
}

void    PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > this->getGradeExec())
        throw AForm::GradeTooLowException();
	if (!this->getSignStat())
        throw AForm::NotSignedException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}