#ifndef SHRUBERRY_H
# define SHRUBERRY_H

# include "Bureaucrat.hpp"
# include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;


public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &c);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &c);
    
    void execute( const Bureaucrat& executor ) const;
};

#endif