#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _grade(150), _name("NoMan") {return;}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade < 1)
		throw std::invalid_argument("Bureaucrat::GradeTooHighException");
	if (grade > 150)
		throw std::invalid_argument("Bureaucrat::GradeTooLowException");
	this->_grade = grade;
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &b) : _grade(b._grade),  _name(b._name) {return;}

Bureaucrat::~Bureaucrat(void) {return;}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &b)
{
	if (this != &b)
		this->_grade = b._grade;
	return (*this);
}

std::string const Bureaucrat::getName(void)
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void)
{
	return (this->_grade);
}

void	Bureaucrat::increaseGrade(void)
{
	if (this->_grade == 1)
		throw std::invalid_argument("Bureaucrat::GradeTooHighException");
	else
		this->_grade--;
	return;
}

void	Bureaucrat::decreaseGrade(void)
{
	if (this->_grade == 150)
		throw std::invalid_argument("Bureaucrat::GradeTooLowException");
	else
		this->_grade++;
	return;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &b)
{
	o << b.getName() << ", Bureaucrat grade " << b.getGrade() << ".";
	return (o);
}