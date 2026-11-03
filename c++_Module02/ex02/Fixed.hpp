/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:00:06 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/15 15:58:26 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>

class Fixed
{
	public:
					Fixed(void);
					Fixed(const int value);
					Fixed(const float value);
					Fixed(const Fixed &other);
					Fixed &operator=(const Fixed &other);
					~Fixed(void);
		int 		getRawBits(void) const; // lire la valeur interne
		void		setRawBits(int const raw); //  modifier la valeur interne

		float		toFloat(void) const; // lire la valeur dans un format float
		int			toInt(void) const; // lire la valeur dans un format int

		// Opérateurs de comparaison
		bool		operator>(const Fixed &other) const;
		bool		operator<(const Fixed &other) const;
		bool		operator>=(const Fixed &other) const;
		bool		operator<=(const Fixed &other) const;
		bool		operator==(const Fixed &other) const;
		bool		operator!=(const Fixed &other) const;

		// Opérateurs arithmétiques
		Fixed		operator+(const Fixed &other) const;
		Fixed		operator-(const Fixed &other) const;
		Fixed		operator*(const Fixed &other) const;
		Fixed		operator/(const Fixed &other) const;

		// Opérateurs d’incrémentation / décrémentation
		Fixed &operator++();     // pré-incrémentation
		Fixed operator++(int);   // post-incrémentation
		Fixed &operator--();     // pré-décrémentation
		Fixed operator--(int);   // post-décrémentation

		// Fonctions statiques min / max
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

	private:
		int 				_fixedPointValue;
		static const int	_fractionalBits = 8;
};

// opérateur d’insertion dans un flux
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
