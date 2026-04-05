#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdlib>

int	main(int argumentCount, char **argumentValues)
{
	if (argumentCount != 6)
	{
		std::cout << "Usage: " << "./file " << "[Bureaucrat name] "	<< "[Bureaucrat grade] "
		<< "[Form name] " << "[Grade to sign] "	<< "[Grade to execute]" << std::endl;

		return 0;
	}

	try
	{
		std::string	bureaucratName = argumentValues[1];
		int			bureaucratGrade = atoi(argumentValues[2]);
		std::string	formName = argumentValues[3];
		int			signGrade = atoi(argumentValues[4]);
		int			executeGrade = atoi(argumentValues[5]);

		Bureaucrat	bureaucrat(bureaucratName, bureaucratGrade);
		Form		formStorage(formName, signGrade, executeGrade);

		std::cout << bureaucrat;
		std::cout << formStorage;
		bureaucrat.signForm(formStorage);
		std::cout << formStorage;
		bureaucrat.signForm(formStorage);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
