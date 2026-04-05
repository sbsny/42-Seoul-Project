#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	storedName;
		bool				signedStatusFlag;
		int const			signGradeLimit;
		int const			executeGradeLimit;

	public:
		Form();
		Form(std::string const formName, int signGrade, int executeGrade);
		Form(Form const &source);
		Form &operator=(Form const &source);
		~Form();

		std::string const	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void	beSigned(Bureaucrat const &bureaucrat);

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

		class AlreadySignedException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &outputStream, Form const &formStorage);

#endif
