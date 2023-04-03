#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <stdexcept>
# include "./Form.hpp"

class Bureaucrat
{
	private:
		int					_grade;
		std::string const	_name;
	
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &b);
		~Bureaucrat(void);

		Bureaucrat &operator=(Bureaucrat const &b);

		std::string const	getName(void);
		int					getGrade(void);

		void	increaseGrade(void);
		void	decreaseGrade(void);
		void	signForm(Form &f);
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &b);

#endif