#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>

int	main(int argumentCount, char **argumentValues)
{
	if (argumentCount != 5)
	{
		std::cout << "Usage: " << "./file "	<< "[Test number] "
		<< "[Target] " << "[Bureaucrat name] " << "[Bureaucrat grade] " << std::endl;

		return 0;
	}

	try
	{
		int			testNumber = atoi(argumentValues[1]);
		std::string	targetValue = argumentValues[2];
		std::string	bureaucratName = argumentValues[3];
		int			bureaucratGrade = atoi(argumentValues[4]);

		Form		*selectedForm = NULL;
		Bureaucrat	bureaucrat(bureaucratName, bureaucratGrade);

		if (testNumber == 1)
			selectedForm = new ShrubberyCreationForm(targetValue);
		else if (testNumber == 2)
			selectedForm = new RobotomyRequestForm(targetValue);
		else if (testNumber == 3)
			selectedForm = new PresidentialPardonForm(targetValue);

		std::cout << bureaucrat;
		std::cout << *selectedForm;
		bureaucrat.executeForm(*selectedForm);
		bureaucrat.signForm(*selectedForm);
		std::cout << *selectedForm;
		bureaucrat.executeForm(*selectedForm);

		delete selectedForm;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
