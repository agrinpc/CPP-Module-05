#include "./Bureaucrat.hpp"
#include "./Form.hpp"

int	main(void)
{
	Bureaucrat a("First", 48);
	Bureaucrat b;
	Bureaucrat d(a);

	try
	{
		Bureaucrat c("Second", -100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << d << std::endl;

	try
	{
		b.decreaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}