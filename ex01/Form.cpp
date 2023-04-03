#include "./Form.hpp"

Form::Form(void) : _name("NoMan"), _is_signed(false), _grade_sign(150), _grade_exec(150) {return;}

Form::Form(std::string const name, int grade_sign, int grade_exec) : _name(name), _is_signed(false), _grade_sign(150), _grade_exec(150)
{
	if (grade_sign < 1)
		throw std::invalid_argument("Form::GradeTooHighException");
	if (grade_sign > 150)
		throw std::invalid_argument("Form::GradeTooLowException");
	if (grade_exec < 1)
		throw std::invalid_argument("Form::GradeTooHighException");
	if (grade_exec > 150)
		throw std::invalid_argument("Form::GradeTooLowException");
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

int const	Form::getGradeSign(void)
{
	return (this->_grade_sign);
}

int const	Form::getGradeExec(void)
{
	return (this->_grade_exec);
}

bool	Form::getSignStat(void)
{
	return (this->_is_signed);
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeSign())
		this->_is_signed = true;
	else
		throw std::invalid_argument("Form::GradeTooLowException");
	b.signForm(*this);
}

std::ostream &operator<<(std::ostream &o, Form &b)
{
	o << b.getName() << ", Sign grade " << b.getGradeSign() << ", execution grade " << b.getGradeExec() << "and is " << (b.getSignStat() ? "" : "NOT") << "signed.";
	return (o);
}