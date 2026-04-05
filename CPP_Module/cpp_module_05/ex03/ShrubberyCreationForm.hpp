#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		std::string	targetLabelValue;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &sourceCopy);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &sourceValue);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string targetValue);

		void	action() const;

		class OpenException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class WriteException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class CloseException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

#endif
