/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:48:02 by nippolit          #+#    #+#             */
/*   Updated: 2025/12/06 13:58:15 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) :
	_max(N)
{
}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_max = other._max;
		this->_vec = other._vec;
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int value)
{
	if (_vec.size() >= _max)
		throw std::runtime_error("Span is full");
	_vec.push_back(value);
}

int	Span::shortestSpan() const
{
	if (_vec.size() <= 1)
		throw std::runtime_error("Not enough numbers to find a span");

	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());

	int minSpan = std::abs(tmp[1] - tmp[0]);

	for (size_t i = 1; i < tmp.size() - 1; i++)
	{
		int span = std::abs(tmp[i + 1] - tmp[i]);
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (_vec.size() <= 1)
		throw std::runtime_error("Not enough numbers to find a span");

	int minVal = *std::min_element(_vec.begin(), _vec.end());
	int maxVal = *std::max_element(_vec.begin(), _vec.end());

	return (maxVal - minVal);
}
