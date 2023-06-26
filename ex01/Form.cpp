#include "./Form.hpp"

Form::Form(void) : _name("NoMan"), _is_signed(false), _grade_sign(150), _grade_exec(150) {return;}

Form::Form(std::string const name, int grade_sign, int grade_exec) : _name(name), _is_signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (grade_sign < 1)
		throw Form::GradeTooHighException();
	if (grade_sign > 150)
		throw Form::GradeTooLowException();
	if (grade_exec < 1)
		throw Form::GradeTooHighException();
	if (grade_exec > 150)
		throw Form::GradeTooLowException();
	return;
}

Form::Form(Form const &f) :  _name(f._name), _is_signed(f._is_signed), _grade_sign(f._grade_sign), _grade_exec(f._grade_exec) {return;}

Form::~Form(void) {return;}

Form &Form::operator=(Form const &f)
{
	if (this != &f)
		this->_is_signed = f._is_signed;
	return (*this);
}

std::string const Form::getName(void)
{
	return (this->_name);
}

int	Form::getGradeSign(void)
{
	return (this->_grade_sign);
}

int	Form::getGradeExec(void)
{
	return (this->_grade_exec);
}

bool	Form::getSignStat(void)
{
	return (this->_is_signed);
}

int	Form::beSigned(Bureaucrat &b)
{	if (this->_is_signed == true)
		return (1);
	if (b.getGrade() <= this->getGradeSign())
	{
		this->_is_signed = true;
		return (0);
	}
	std::cout << b.getName() << " couldn’t sign " << this->getName() << " because it has a lower Grade " << std::endl;
	throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, Form &b)
{
	o << b.getName() << ", Sign grade " << b.getGradeSign() << ", execution grade " << b.getGradeExec() << "and is " << (b.getSignStat() ? "" : "NOT") << "signed.";
	return (o);
}