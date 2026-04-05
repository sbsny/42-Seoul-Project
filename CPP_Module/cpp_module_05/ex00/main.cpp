#include "Bureaucrat.hpp"
#include <cstdlib>

int	main(int argumentCount, char **argumentValues)
{
	if (argumentCount != 3)
	{
		std::cout << "Usage: " << "./file "	<< "[Bureaucrat name] "
		<< "[Bureaucrat grade]" << std::endl;

		return 0;
	}

	try
	{
		std::string	bureaucratName = argumentValues[1];
		int			bureaucratGrade = atoi(argumentValues[2]);

		Bureaucrat	bureaucrat(bureaucratName, bureaucratGrade);

		std::cout << bureaucrat;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
