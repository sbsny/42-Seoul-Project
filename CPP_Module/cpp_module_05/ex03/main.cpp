#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>

int	main(int argumentCount, char **argumentValues)
{
	if (argumentCount != 5)
	{
		std::cout << "Usage: " << "./file "	<< "[Bureaucrat name] "
		<< "[Bureaucrat grade] " << "[Target] " << "[Form name]" << std::endl;

		return 0;
	}

	try
	{
		std::string	bureaucratName = argumentValues[1];
		int			bureaucratGrade = atoi(argumentValues[2]);
		std::string	targetValue = argumentValues[3];
		std::string	formName = argumentValues[4];

		Intern		intern;
		Bureaucrat	bureaucrat(bureaucratName, bureaucratGrade);
		Form		*createdForm = intern.makeForm(formName, targetValue);

		std::cout << bureaucrat;
		std::cout << *createdForm;
		bureaucrat.signForm(*createdForm);
		bureaucrat.executeForm(*createdForm);

		delete createdForm;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
