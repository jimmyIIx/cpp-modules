/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:49:21 by nippolit          #+#    #+#             */
/*   Updated: 2025/10/27 15:17:51 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>   // pour std::atoi, std::atof si besoin
#include <iomanip>   // pour std::setprecision

class ScalarConverter
{
	private:
				ScalarConverter(void);
				ScalarConverter(const ScalarConverter& other);
				ScalarConverter& operator=(const ScalarConverter& other);
				~ScalarConverter(void);

	public:
		static void	convert(std::string const &literal);
};
