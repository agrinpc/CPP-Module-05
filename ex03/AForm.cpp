#include "./AForm.hpp"

AForm::AForm(void) : _name("NoMan"), _is_signed(false), _grade_sign(150), _grade_exec(150) {return;}

AForm::AForm(std::string const name, int grade_sign, int grade_exec) : _name(name), _is_signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (grade_sign < 1)
		throw AForm::GradeTooHighException();
	if (grade_sign > 150)
		throw AForm::GradeTooLowException();
	if (grade_exec < 1)
		throw AForm::GradeTooHighException();
	if (grade_exec > 150)
		throw AForm::GradeTooLowException();
	return;
}

AForm::AForm(AForm const &f) :  _name(f._name), _is_signed(f._is_signed), _grade_sign(f._grade_sign), _grade_exec(f._grade_exec) {return;}

AForm::~AForm(void) {return;}

AForm &AForm::operator=(AForm const &f)
{
	if (this != &f)
		this->_is_signed = f._is_signed;
	return (*this);
}

std::string const AForm::getName(void) const
{
	return (this->_name);
}

int	AForm::getGradeSign(void) const
{
	return (this->_grade_sign);
}

int	AForm::getGradeExec(void) const
{
	return (this->_grade_exec);
}

bool	AForm::getSignStat(void) const
{
	return (this->_is_signed);
}

int	AForm::beSigned(Bureaucrat &b)
{	if (this->_is_signed == true)
		return (1);
	if (b.getGrade() <= this->getGradeSign())
	{
		this->_is_signed = true;
		return (0);
	}
	std::cout << b.getName() << " couldn’t sign " << this->getName() << " because it has a lower Grade " << std::endl;
	throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, AForm &b)
{
	o << b.getName() << ", Sign grade " << b.getGradeSign() << ", execution grade " << b.getGradeExec() << "and is " << (b.getSignStat() ? "" : "NOT") << "signed.";
	return (o);
}