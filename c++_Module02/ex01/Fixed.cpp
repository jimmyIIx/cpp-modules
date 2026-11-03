/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:18:27 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/15 15:36:45 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// constructeur par defaut
Fixed::Fixed(void) :
	_fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// contructeur pour valeur int (converteur int en (bit) a virgule)
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;
}

// contructeur pour valeur float (converteur float en (bit) a virgule)
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

// destructeur
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// constructeur de recopie
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	_fixedPointValue = other.getRawBits();
}

// opérateur d’affectation
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_fixedPointValue = other.getRawBits();
	return *this;
}

int
Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}

void
Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

// convertis nombre (bit a vigule) en float
float
Fixed::toFloat(void) const
{
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

// convertis nombre (bit a vigule) en int
int
Fixed::toInt(void) const
{
	return _fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
