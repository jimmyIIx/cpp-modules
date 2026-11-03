/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:18:15 by nippolit          #+#    #+#             */
/*   Updated: 2026/03/08 18:19:54 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>   // std::atoi
#include <climits>   // INT_MAX
#include <cctype>
#include <sys/time.h>
#include <algorithm>
#include <cerrno>

PmergeMe::PmergeMe() :
	_vectorTime(0),
	_dequeTime(0)
{
}

PmergeMe::PmergeMe(char **av) :
	_vectorTime(0),
	_dequeTime(0)
{
	parseArgs(av);
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
		_vectorTime = other._vectorTime;
		_dequeTime = other._dequeTime;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::parseArgs(char **argv)
{
	for (size_t i = 0; argv[i]; i++)
	{
		std::string s(argv[i]);
		if (s.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cerr << "Error: not number\n";
			std::exit(1);
		}

		errno = 0;
		long value = std::strtol(argv[i], NULL, 10);

		if (errno == ERANGE)
		{
			std::cerr << "Error: overflow long\n";
			std::exit(1);
		}
		if (value < 0)
		{
			std::cerr << "Error: negative number\n";
			std::exit(1);
		}
		if (value > INT_MAX)
		{
			std::cerr << "Error: overflow int\n";
			std::exit(1);
		}

		_vector.push_back(static_cast<int>(value));
		_deque.push_back(static_cast<int>(value));
	}
}

const std::vector<int>& PmergeMe::getVector() const
{
	return _vector;
}

const std::deque<int>& PmergeMe::getDeque() const
{
	return _deque;
}

double	PmergeMe::getVectorTime() const
{
	return _vectorTime;
}

double	PmergeMe::getDequeTime() const
{
	return _dequeTime;
}

void	PmergeMe::sortVector()
{
	struct timeval start, end;
	gettimeofday(&start, NULL);

	std::vector<int> smalls;
	std::vector<int> larges;

	// Séparer en petits et grands
	size_t i = 0;
	while (i + 1 < _vector.size())
	{
		if (_vector[i] < _vector[i + 1])
		{
			smalls.push_back(_vector[i]);
			larges.push_back(_vector[i + 1]);
		}
		else
		{
			smalls.push_back(_vector[i + 1]);
			larges.push_back(_vector[i]);
		}
		i += 2;
	}
	if (i < _vector.size())
		smalls.push_back(_vector[i]);

	// Tri insertion sur larges
	for (size_t i = 1; i < larges.size(); i++)
	{
		int key = larges[i];
		int j = i - 1;
		while (j >= 0 && larges[j] > key)
		{
			larges[j + 1] = larges[j];
			if (j == 0) break; // éviter underflow
			j--;
		}
		if (j == 0 && larges[0] > key)
			larges[0] = key;
		else
			larges[j + 1] = key;
	}

	// Insertion des petits éléments dans larges
	for (size_t s = 0; s < smalls.size(); s++)
	{
		int val = smalls[s];
		size_t pos = 0;
		while (pos < larges.size() && larges[pos] < val)
			pos++;

		larges.insert(larges.begin() + pos, val); // insertion manuelle
	}

	_vector = larges;

	gettimeofday(&end, NULL);
	_vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

void	PmergeMe::sortDeque()
{
	struct timeval start, end;
	gettimeofday(&start, NULL);

	std::deque<int> smalls;
	std::deque<int> larges;

	size_t i = 0;
	while (i + 1 < _deque.size())
	{
		if (_deque[i] < _deque[i + 1])
		{
			smalls.push_back(_deque[i]);
			larges.push_back(_deque[i + 1]);
		}
		else
		{
			smalls.push_back(_deque[i + 1]);
			larges.push_back(_deque[i]);
		}
		i += 2;
	}
	if (i < _deque.size())
		smalls.push_back(_deque[i]);

	// Tri insertion sur larges
	for (size_t i = 1; i < larges.size(); i++)
	{
		int key = larges[i];
		int j = i - 1;
		while (j >= 0 && larges[j] > key)
		{
			larges[j + 1] = larges[j];
			if (j == 0) break;
			j--;
		}
		if (j == 0 && larges[0] > key)
			larges[0] = key;
		else
			larges[j + 1] = key;
	}

	// Insertion des petits éléments
	for (size_t s = 0; s < smalls.size(); s++)
	{
		int val = smalls[s];
		size_t pos = 0;
		while (pos < larges.size() && larges[pos] < val)
			pos++;

		larges.insert(larges.begin() + pos, val);
	}

	_deque = larges;

	gettimeofday(&end, NULL);
	_dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}
