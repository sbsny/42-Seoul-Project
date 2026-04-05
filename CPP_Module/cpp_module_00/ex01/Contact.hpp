

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>

class Contact
{
	private:
		std::string	preData[5];
		std::string	dataValue[5];

	public:
		Contact();

		void	addContact();
		void	printContact();
		void	printAll();
};

#endif
