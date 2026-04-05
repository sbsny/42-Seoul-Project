#include "RPN.hpp"

static void	exit_with_error(std::string const &message)
{
	std::cout << message << std::endl;
	std::exit(1);
}

static std::string	removeSpaces(std::string expression)
{
	expression.erase(std::remove(expression.begin(), expression.end(), ' '),
		expression.end());
	return expression;
}

RPN::RPN() : firstOperand(0), secondOperand(0), _expression(""), _valueStack()
{
}

RPN::RPN(std::string expression)
	: firstOperand(0), secondOperand(0), _expression(expression), _valueStack()
{
	calculation();
}

RPN::RPN(const RPN &source)
	: firstOperand(source.firstOperand), secondOperand(source.secondOperand),
	_expression(source._expression), _valueStack(source._valueStack)
{
}

RPN	&RPN::operator=(const RPN &source)
{
	if (this != &source)
	{
		this->firstOperand = source.firstOperand;
		this->secondOperand = source.secondOperand;
		this->_expression = source._expression;
		this->_valueStack = source._valueStack;
	}
	return *this;
}

RPN::~RPN()
{
}

void	RPN::calculation()
{
	std::string	trimmedExpression = removeSpaces(this->_expression);

	this->_valueStack = std::stack<int>();
	for (std::size_t characterIndex = 0; characterIndex < trimmedExpression.length();
		characterIndex++)
	{
		char	token = trimmedExpression[characterIndex];

		if (std::isdigit(token))
		{
			this->_valueStack.push(static_cast<int>(token) - '0');
			continue ;
		}
		if (token != '+' && token != '-' && token != '*' && token != '/')
			exit_with_error("Error: Wrong character");
		if (this->_valueStack.size() < 2)
			exit_with_error("Error: Not enough numbers");
		this->firstOperand = this->_valueStack.top();
		this->_valueStack.pop();
		this->secondOperand = this->_valueStack.top();
		this->_valueStack.pop();
		if (token == '+')
			this->_valueStack.push(this->secondOperand + this->firstOperand);
		else if (token == '-')
			this->_valueStack.push(this->secondOperand - this->firstOperand);
		else if (token == '*')
			this->_valueStack.push(this->secondOperand * this->firstOperand);
		else
		{
			if (this->firstOperand == 0)
				exit_with_error("Error: Can't be divided by zero");
			this->_valueStack.push(this->secondOperand / this->firstOperand);
		}
	}
	if (this->_valueStack.size() != 1)
		exit_with_error("Error: Stack remains");
	std::cout << this->_valueStack.top() << std::endl;
}
