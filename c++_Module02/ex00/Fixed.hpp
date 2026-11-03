/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:00:06 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/13 13:31:44 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cstdlib>

class Fixed
{
	public:
					Fixed(void);
					Fixed(const Fixed &other);
					Fixed &operator=(const Fixed &other);
					~Fixed(void);
		int 		getRawBits(void) const; // lire la valeur interne
		void		setRawBits(int const raw); //  modifier la valeur interne

	private:
		int 				_fixedPointValue;
		static const int	_fractionalBits = 8;
};
