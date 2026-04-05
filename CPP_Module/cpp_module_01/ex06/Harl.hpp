#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
	private:
		void	debug();
		void	info();
		void	warning();
		void	error();
		int		getLevel(std::string complaintLevel);
	public:
		Harl();
		~Harl();
		void	complain(std::string complaintLevel);
};

#endif
