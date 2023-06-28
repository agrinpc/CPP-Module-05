#ifndef PRESIDENT_H
# define PRESIDENT_H

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;


public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &c);
    ~PresidentialPardonForm();

    PresidentialPardonForm& operator=(const PresidentialPardonForm &c);
    
    void execute( const Bureaucrat& executor ) const;
};

#endif