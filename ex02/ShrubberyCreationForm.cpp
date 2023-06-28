#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :  AForm("Shrubbery_Form", 145, 137), _target("No Target") {return ;}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery_Form", 145, 137), _target(target) {return;}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& c) : AForm(c), _target( c._target) {return;}

ShrubberyCreationForm::~ShrubberyCreationForm() {return;}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &c)
{
    if (this != &c)
		this->_target = c._target;
	return (*this);
}

void    ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > this->getGradeExec())
        throw AForm::GradeTooLowException();
	if (!this->getSignStat())
        throw AForm::NotSignedException();
	std::ofstream f(this->_target + "_shrubbery");
	f << "    oxoxoo    ooxoo" << std::endl << "  ooxoxo oo  oxoxooo" << std::endl;
	f << " oooo xxoxoo ooo ooox" << std::endl << " oxo o oxoxo  xoxxoxo" << std::endl;
	f << "  oxo xooxoooo o ooo" << std::endl << "    ooo\\oo\\  /o/o" << std::endl;
	f << "        \\  \\/ /" << std::endl << "         |   /" << std::endl;
	f << "         |  |" << std::endl << "         | D|" << std::endl;
	f << "         |  |" << std::endl << "         |  |" << std::endl << "  ______/____\\____" << std::endl;
	f.close();
}