

#include "Contact.hpp"

Contact::Contact()
{
	preData[0] = "First name: ";
	preData[1] = "Last name: ";
	preData[2] = "Nickname: ";
	preData[3] = "Phone number: ";
	preData[4] = "Darkest secret: ";
}

void	Contact::addContact()
{
	for (int indexValue = 0; indexValue < 5; indexValue++)
	{
		dataValue[indexValue].clear();
		while (dataValue[indexValue].empty())
		{
			std::cout << preData[indexValue];
			std::getline(std::cin, dataValue[indexValue]);
			if (std::cin.eof())
				exit(0);
		}
	}
}

void	Contact::printContact()
{
	for (int indexValue = 0; indexValue < 3; indexValue++)
	{
		if (dataValue[indexValue].length() > 10)
			std::cout << dataValue[indexValue].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << dataValue[indexValue];
		if (indexValue < 2)
			std::cout << "|";
	}
	std::cout << std::endl;
}

void	Contact::printAll()
{
	for (int indexValue = 0; indexValue < 5; indexValue++)
		std::cout << preData[indexValue] << dataValue[indexValue] << std::endl;
}
