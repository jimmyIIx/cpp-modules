/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:48:14 by nippolit          #+#    #+#             */
/*   Updated: 2025/12/06 13:52:38 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(int value);
		int		shortestSpan() const;
		int		longestSpan() const;

		template <typename It>
		void	addRange(It begin, It end)
		{
			if (std::distance(begin, end) + _vec.size() > _max)
				throw std::runtime_error("Span is full");
			_vec.insert(_vec.end(), begin, end);
		}

	private:
		unsigned int		_max;
		std::vector<int>	_vec;
};
