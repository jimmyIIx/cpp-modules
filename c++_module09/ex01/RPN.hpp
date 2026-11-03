/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:08:30 by nippolit          #+#    #+#             */
/*   Updated: 2025/12/07 11:10:42 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <string>

class RPN
{
		public:
				RPN();
				RPN(const RPN& other);
				RPN& operator=(const RPN& other);
				~RPN();

				int	evaluate(const std::string& expression);

		private:
				std::stack<int> _stack;

				bool	isNumber(const std::string& token) const;
				bool	applyOperator(const std::string& op);
};
