

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		contactCount;
		int		contactIndex;

	public:
		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	searchContact();
};

#endif
