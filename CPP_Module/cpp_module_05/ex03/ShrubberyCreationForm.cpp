#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	Form("ShrubberyCreationForm", 145, 137),
	targetLabelValue("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string targetName) :
	Form("ShrubberyCreationForm", 145, 137),
	targetLabelValue(targetName)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &source) :
	Form(source),
	targetLabelValue(source.targetLabelValue)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &source)
{
	if (this != &source)
	{
		this->targetLabelValue = source.targetLabelValue;
		Form::operator=(source);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void	ShrubberyCreationForm::action() const
{
	std::string		outputFileName = this->targetLabelValue + "_shrubbery";
	std::ofstream	outputFile(outputFileName.c_str());

	if (!outputFile.is_open())
		throw ShrubberyCreationForm::OpenException();
	outputFile << "                  _-_                     " << std::endl;
	outputFile << "               /~~   ~~\\                  " << std::endl;
	outputFile << "            /~~         ~~\\               " << std::endl;
	outputFile << "           {               }              " << std::endl;
	outputFile << "            \\  _-     -_  /               " << std::endl;
	outputFile << "               ~  \\\\ //  ~                " << std::endl;
	outputFile << "           _- -   | | _- _                " << std::endl;
	outputFile << "             _ -  | |   -_                " << std::endl;
	outputFile << "                 /   \\                    " << std::endl;
	if (outputFile.bad())
		throw ShrubberyCreationForm::WriteException();
	outputFile.close();
	if (outputFile.bad())
		throw ShrubberyCreationForm::CloseException();
}

const char	*ShrubberyCreationForm::OpenException::what() const throw()
{
	return "File could not be opened";
}

const char	*ShrubberyCreationForm::WriteException::what() const throw()
{
	return "File could not be written";
}

const char	*ShrubberyCreationForm::CloseException::what() const throw()
{
	return "File could not be closed";
}
