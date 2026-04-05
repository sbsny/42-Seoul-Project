#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	Form("RobotomyRequestForm", 72, 45),
	targetLabelValue("default")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string targetValue) :
	Form("RobotomyRequestForm", 72, 45),
	targetLabelValue(targetValue)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &sourceCopy) :
	Form(sourceCopy),
	targetLabelValue(sourceCopy.targetLabelValue)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &sourceValue)
{
	this->targetLabelValue = sourceValue.targetLabelValue;
	Form::operator=(sourceValue);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void	RobotomyRequestForm::action() const
{
	std::cout << "Drilling noises" << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << this->targetLabelValue << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}
