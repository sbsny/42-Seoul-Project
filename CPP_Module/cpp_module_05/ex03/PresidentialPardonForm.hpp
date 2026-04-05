#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string	targetLabelValue;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &sourceCopy);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &sourceValue);
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string targetValue);

		void	action() const;
};

#endif
