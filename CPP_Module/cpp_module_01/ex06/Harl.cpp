#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n" << std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don't put enough! If you did I would not have to ask for it!\n" << std::endl;
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming here for years and you just started working here last month.\n" << std::endl;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

int	Harl::getLevel(std::string level)
{
	static const char *levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int indexValue = 0; indexValue < 4; ++indexValue)
	{
		if (level == levels[indexValue])
			return indexValue;
	}
	return 4;
}

void Harl::complain(std::string level)
{
	int	idx;

	idx = getLevel(level);
	if (idx == 4)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return ;
	}
	for (int indexValue = idx; indexValue < 4; ++indexValue)
	{
		if (indexValue == 0)
			this->debug();
		else if (indexValue == 1)
			this->info();
		else if (indexValue == 2)
			this->warning();
		else
			this->error();
	}
}
