

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << " < PhoneBook Start > " << std::endl;
	contactCount = 0;
	contactIndex = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << " < PhoneBook EXIT > " << std::endl;
}

void	PhoneBook::addContact()
{
	contacts[contactIndex++].addContact();
	if (contactIndex == 8)
		contactIndex = 0;
	if (contactCount < 8)
		contactCount++;
}

void	PhoneBook::searchContact()
{
	if (contactCount == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return;
	}
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	for (int indexValue = 0; indexValue < contactCount; indexValue++)
	{
		std::cout << std::setw(10) << indexValue << "|";
		contacts[indexValue].printContact();
	}
	bool validIndex = false;
	while (!validIndex)
	{
		std::string input;
		while (input.empty())
		{
			std::cout << "Enter the index of the contact you want to see: ";
			std::getline(std::cin, input);
			if (std::cin.eof())
				exit(0);
		}
		if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
		{
			int index = input[0] - '0';
			if (index < contactCount)
			{
				validIndex = true;
				contacts[index].printAll();
			}
			else
				std::cerr << "Invalid index" << std::endl;
		}
		else
			std::cerr << "Invalid index" << std::endl;
	}
}
