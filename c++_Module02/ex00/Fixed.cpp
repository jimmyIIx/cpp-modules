/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:18:27 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/13 19:04:24 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// constructeur par defaut
Fixed::Fixed(void) :
	_fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
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
