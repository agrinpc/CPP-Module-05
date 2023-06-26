#ifndef FORM_H
# define FORM_H

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const	_name;
		bool				_is_signed;
		int	const			_grade_sign;
		int	const			_grade_exec;

	public:
		Form(void);
		Form(std::string name, int grade_signe, int grade_exec);
		Form(Form const &f);
		~Form(void);

		Form &operator=(Form const &f);

		std::string const	getName(void);
		int		getGradeSign(void);
		int		getGradeExec(void);
		bool	getSignStat(void);

		int		beSigned(Bureaucrat &b);
		
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{ 
					return ("Form::GradeTooHighException"); 
				}
		};
		class GradeTooLowException: public std::exception 
		{
			public:
				virtual const char* what() const throw()
				{ 
					return ("Form::GradeTooLowException"); 
				}
		};
};

std::ostream &operator<<(std::ostream &o, Form &f);

#endif