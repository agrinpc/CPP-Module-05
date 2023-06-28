#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) :  AForm("Robot_Form", 72, 45), _target("No Target") {return ;}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robot_Form", 72, 45), _target(target) {return;}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& c) : AForm(c), _target( c._target) {return;}

RobotomyRequestForm::~RobotomyRequestForm() {return;}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &c)
{
    if (this != &c)
		this->_target = c._target;
	return (*this);
}

void    RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	int	rand;

    if (executor.getGrade() > this->getGradeExec())
        throw AForm::GradeTooLowException();
	if (!this->getSignStat())
        throw AForm::NotSignedException();
    else
	{
		std::cout << "DRRRRRRRRRRRRRRRRRRR..." << std::endl;
		std::srand(std::time(NULL));
		rand = std::rand();
		if (rand % 2 == 1)
       		std::cout << this->_target << " has been robotomized successfully." << std::endl;
		else
			std::cout << "The robotomy failed." << std::endl;
    }
}