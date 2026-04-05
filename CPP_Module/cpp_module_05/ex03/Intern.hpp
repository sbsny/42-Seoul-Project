#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		Form	*makeShrubberyCreationForm(std::string const &targetValue);
		Form	*makeRobotomyRequestForm(std::string const &targetValue);
		Form	*makePresidentialPardonForm(std::string const &targetValue);

	public:
		Intern();
		Intern(Intern const &source);
		Intern &operator=(Intern const &source);
		~Intern();

		Form	*makeForm(std::string const &formName, std::string const &targetValue);

		class UnknownFormException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
