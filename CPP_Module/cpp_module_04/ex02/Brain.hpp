#include <iostream>

#ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain
{
	private:
		std::string thoughtStorage[100];

	public:
		Brain();
		Brain(const Brain &source);
		~Brain();

		Brain&	operator=(const Brain &source);

		std::string	getIdeas(int ideaIndex) const;
		void		setIdeas(std::string ideaText, int ideaIndex);
};

#endif
