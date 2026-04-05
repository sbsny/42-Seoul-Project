#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	Form("PresidentialPardonForm", 25, 5),
	targetLabelValue("default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string targetName) :
	Form("PresidentialPardonForm", 25, 5),
	targetLabelValue(targetName)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &source) :
	Form(source),
	targetLabelValue(source.targetLabelValue)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &source)
{
	if (this != &source)
	{
		Form::operator=(source);
		this->targetLabelValue = source.targetLabelValue;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void	PresidentialPardonForm::action() const
{
	std::cout << this->targetLabelValue << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
