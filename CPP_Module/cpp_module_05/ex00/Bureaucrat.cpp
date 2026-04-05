#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : storedGrade(150), storedName("default") {}

Bureaucrat::Bureaucrat(std::string const storedName, int storedGrade) : storedGrade(storedGrade), storedName(storedName)
{
	if (storedGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (storedGrade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &sourceCopy) : storedGrade(sourceCopy.storedGrade), storedName(sourceCopy.storedName)
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &sourceValue)
{
	this->storedGrade = sourceValue.storedGrade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string const	Bureaucrat::getName() const
{
	return this->storedName;
}

int	Bureaucrat::getGrade() const
{
	return this->storedGrade;
}

void	Bureaucrat::incrementGrade()
{
	if (this->storedGrade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->storedGrade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->storedGrade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->storedGrade++;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade is too high";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade is too low";
}

std::ostream	&operator<<(std::ostream &outputStream, Bureaucrat const &bureaucrat)
{
	outputStream << bureaucrat.getName() << ", bureaucrat grade "
	<< bureaucrat.getGrade() << std::endl;
	return outputStream;
}
