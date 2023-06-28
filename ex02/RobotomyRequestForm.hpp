#ifndef ROBOT_H
# define ROBOT_H

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &c);
    ~RobotomyRequestForm();

    RobotomyRequestForm& operator=(const RobotomyRequestForm &c);
    
    void execute( const Bureaucrat& executor ) const;
};

#endif