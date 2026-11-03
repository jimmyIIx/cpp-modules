/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:18:18 by nippolit          #+#    #+#             */
/*   Updated: 2025/12/13 13:20:00 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sys/time.h>

class PmergeMe
{
		public:
				PmergeMe();
				PmergeMe(char **av);
				PmergeMe(const PmergeMe& other);
				PmergeMe& operator=(const PmergeMe& other);
				~PmergeMe();

				void						sortVector();
				void						sortDeque();

				const std::vector<int>&		getVector() const;
				const std::deque<int>&		getDeque() const;

				double						getVectorTime() const;
				double						getDequeTime() const;

		private:
				std::vector<int>			_vector;
				std::deque<int>				_deque;

				double						_vectorTime;
				double						_dequeTime;

				void						parseArgs(char **argv);
};
