#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>

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

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{ 
					return ("Bureaucrat::GradeTooHighException"); 
				}
		};
		class GradeTooLowException: public std::exception 
		{
			public:
				virtual const char* what() const throw()
				{ 
					return ("Bureaucrat::GradeTooLowException"); 
				}
		};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &b);

#endif