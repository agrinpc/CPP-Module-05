#ifndef FORM_H
# define FORM_H

# include <iostream>
# include "Bureaucrat.hpp"

class AForm
{
	private:
		std::string const	_name;
		bool				_is_signed;
		int	const			_grade_sign;
		int	const			_grade_exec;

	public:
		AForm(void);
		AForm(std::string name, int grade_signe, int grade_exec);
		AForm(AForm const &f);
		virtual ~AForm(void);

		AForm &operator=(AForm const &f);

		std::string const	getName(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;
		bool				getSignStat(void) const;
		int					beSigned(Bureaucrat &b);
		virtual void		execute( const Bureaucrat &executor ) const = 0;
		
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
		class NotSignedException: public std::exception 
		{
			public:
				virtual const char* what() const throw()
				{ 
					return ("Form::NotSignedException"); 
				}
		};
};

std::ostream &operator<<(std::ostream &o, AForm &f);

#endif