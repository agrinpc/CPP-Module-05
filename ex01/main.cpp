#include "./Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat a("First", 48);
	Bureaucrat b;

	try
	{
		Bureaucrat c("Second", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;

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