

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phoneBook;

	while (true)
	{
		std::string input;
		while (input.empty())
		{
			std::cout << "Enter a command: ";
			std::getline(std::cin, input);
			if (std::cin.eof())
				exit (0);
		}
		if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
			phoneBook.searchContact();
		else if (input == "EXIT")
			break;
		else
			std::cerr << "Invalid command" << std::endl;
	}
	return 0;
}
