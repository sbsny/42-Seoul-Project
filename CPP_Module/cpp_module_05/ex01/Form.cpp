#include "Form.hpp"

static void	validateGradeRange(int signGrade, int executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form() :
	storedName("default"),
	signedStatusFlag(false),
	signGradeLimit(150),
	executeGradeLimit(150)
{}

Form::Form(std::string const formName, int signGrade, int executeGrade) :
	storedName(formName),
	signedStatusFlag(false),
	signGradeLimit(signGrade),
	executeGradeLimit(executeGrade)
{
	validateGradeRange(signGrade, executeGrade);
}

Form::Form(Form const &source) :
	storedName(source.storedName),
	signedStatusFlag(source.signedStatusFlag),
	signGradeLimit(source.signGradeLimit),
	executeGradeLimit(source.executeGradeLimit)
{
}

Form &Form::operator=(Form const &source)
{
	if (this != &source)
		this->signedStatusFlag = source.signedStatusFlag;
	return *this;
}

Form::~Form() {}

std::string const	Form::getName() const
{
	return this->storedName;
}

bool	Form::getSigned() const
{
	return this->signedStatusFlag;
}

int	Form::getGradeToSign() const
{
	return this->signGradeLimit;
}

int	Form::getGradeToExecute() const
{
	return this->executeGradeLimit;
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGradeLimit)
		throw Form::GradeTooLowException();
	if (this->signedStatusFlag)
		throw Form::AlreadySignedException();
	this->signedStatusFlag = true;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade is too high";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade is too low";
}

const char	*Form::AlreadySignedException::what() const throw()
{
	return "Form is already signed";
}

std::ostream	&operator<<(std::ostream &outputStream, Form const &formStorage)
{
	outputStream << formStorage.getName() << " is "
	<< (formStorage.getSigned() ? "signed" : "unsigned")
	<< ", it requires a grade of " << formStorage.getGradeToSign()
	<< " to be signed and a grade of " << formStorage.getGradeToExecute()
	<< " to be executed" << std::endl;
	return outputStream;
}
