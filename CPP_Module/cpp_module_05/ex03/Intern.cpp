
#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &source)
{
	*this = source;
}

Intern &Intern::operator=(Intern const &source)
{
	(void)source;
	return *this;
}

Intern::~Intern() {}

Form	*Intern::makeShrubberyCreationForm(std::string const &targetValue)
{
	return new ShrubberyCreationForm(targetValue);
}

Form	*Intern::makeRobotomyRequestForm(std::string const &targetValue)
{
	return new RobotomyRequestForm(targetValue);
}

Form	*Intern::makePresidentialPardonForm(std::string const &targetValue)
{
	return new PresidentialPardonForm(targetValue);
}

Form	*Intern::makeForm(std::string const &formName, std::string const &targetValue)
{
	Form	*(Intern::*formFactories[3])(std::string const &) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};
	std::string	availableForms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int formIndex = 0; formIndex < 3; formIndex++)
	{
		if (formName == availableForms[formIndex])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formFactories[formIndex])(targetValue);
		}
	}
	throw Intern::UnknownFormException();
}

const char *Intern::UnknownFormException::what() const throw()
{
	return "Intern: Unknown form";
}
