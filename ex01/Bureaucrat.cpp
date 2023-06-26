#include "./Bureaucrat.hpp"
#include "./Form.hpp"

Bureaucrat::Bureaucrat(void) : _grade(150), _name("NoMan") {return;}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
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
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
	return;
}

void	Bureaucrat::decreaseGrade(void)
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
	return;
}

void	Bureaucrat::signForm(Form &f)
{
	int	ret;
	ret = f.beSigned(*this);
	if (ret == 1)
		std::cout << this->getName() << " couldn’t sign " << f.getName() << " because it is already signed" << std::endl;
	else if (ret == 0)
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	
	

}

std::ostream &operator<<(std::ostream &o, Bureaucrat &b)
{
	o << b.getName() << ", Bureaucrat grade " << b.getGrade() << ".";
	return (o);
}