#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		int					storedGrade;
		std::string const	storedName;

	public:
		Bureaucrat();
		Bureaucrat(std::string const storedName, int storedGrade);
		Bureaucrat(Bureaucrat const &sourceCopy);
		Bureaucrat &operator=(Bureaucrat const &sourceValue);
		~Bureaucrat();

		std::string const	getName() const;
		int					getGrade() const;

		void	incrementGrade();
		void	decrementGrade();

		void	signForm(Form &formStorage);

		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &outputStream, Bureaucrat const &bureaucrat);

#endif
