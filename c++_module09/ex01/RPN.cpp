/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:08:19 by nippolit          #+#    #+#             */
/*   Updated: 2025/12/07 11:13:45 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>

RPN::RPN()
{
}

RPN::RPN(const RPN& other) :
	_stack(other._stack)
{
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN()
{

}

bool	RPN::isNumber(const std::string& token) const
{
	return token.length() == 1 && token[0] >= '0' && token[0] <= '9';
}

bool	RPN::applyOperator(const std::string& op)
{
	if (_stack.size() < 2)
		return false;

	int b = _stack.top(); _stack.pop();
	int a = _stack.top(); _stack.pop();
	int result;

	if (op == "+") result = a + b;
	else if (op == "-") result = a - b;
	else if (op == "*") result = a * b;
	else if (op == "/")
	{
		if (b == 0) return false; // division par zéro
		result = a / b;
	}
	else
		return false; // opérateur invalide

	_stack.push(result);
	return true;
}

int	RPN::evaluate(const std::string& expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (isNumber(token))
			_stack.push(token[0] - '0');
		else if (!applyOperator(token))
		{
			std::cerr << "Error" << std::endl;
			throw std::runtime_error("Invalid expression");
		}
	}

	if (_stack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		throw std::runtime_error("Invalid expression");
	}

	int result = _stack.top();
	_stack.pop();
	return result;
}
