#include "./Bureaucrat.hpp"
#include "./Form.hpp"

int	main(void)
{
	Bureaucrat	*b1 = new Bureaucrat("Milad", 45);
	Form		*f1 = new Form("Form 1", 100, 150);
	Form		*f2 = new Form("Form 2", 5, 10);

	std::cout << b1->getName() << " and " << f1->getName() << "." << std::endl;
	try
	{
		std::cout << "Signing " << f1->getName() << "." << std::endl;
		b1->signForm(*f1);
		std::cout << "Resigning " << f1->getName() << "." << std::endl;
		b1->signForm(*f1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << b1->getName() << " and " << f2->getName() << "." << std::endl;
	try
	{
		std::cout << "Signing " << f2->getName() << "." << std::endl;
		b1->signForm(*f2);
		std::cout << "Resigning " << f2->getName() << "." << std::endl;
		b1->signForm(*f2);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete b1; delete f1; delete f2;
	return (0);
}