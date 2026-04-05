#ifndef RPN_HPP
# define RPN_HPP
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>

class RPN
{
	private:
		int				firstOperand;
		int				secondOperand;
		std::string		_expression;
		std::stack<int>	_valueStack;

	public:
		RPN();
		RPN(std::string expression);
		RPN(const RPN &source);
		RPN	&operator=(const RPN &source);
		~RPN();

		void	calculation();
};

#endif
