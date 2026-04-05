#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	Form("PresidentialPardonForm", 25, 5),
	targetLabelValue("default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string targetValue) :
	Form("PresidentialPardonForm", 25, 5),
	targetLabelValue(targetValue)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &sourceCopy) :
	Form(sourceCopy),
	targetLabelValue(sourceCopy.targetLabelValue)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &sourceValue)
{
	this->targetLabelValue = sourceValue.targetLabelValue;
	Form::operator=(sourceValue);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void	PresidentialPardonForm::action() const
{
	std::cout << this->targetLabelValue << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
