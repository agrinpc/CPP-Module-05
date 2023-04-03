#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <stdexcept>
# include "./Bureaucrat.hpp"

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
		int	const			getGradeSign(void);
		int	const			getGradeExec(void);
		bool				getSignStat(void);

		void	beSigned(Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &o, Form &f);

#endif