#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <exception>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string	targetLabelValue;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &sourceCopy);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &sourceValue);
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string targetValue);

		void	action() const;
};

#endif
