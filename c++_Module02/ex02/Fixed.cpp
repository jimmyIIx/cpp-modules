/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:18:27 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/15 16:34:33 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// constructeur par defaut
Fixed::Fixed(void) :
	_fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// contructeur pour valeur int (converteur int en virgule fixe (bit a virgule)
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;
}

// contructeur pour valeur float (converteur float en virgule fixe (bit a virgule)
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

// Lire la valeur
int
Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}

// Modifier la valeur
void
Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

// Convertis virgule fixe (nombre en bit a vigule) en float simple
float
Fixed::toFloat(void) const
{
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

// convertis virgule fixe (nombre en bit a vigule) en int simple
int
Fixed::toInt(void) const
{
	return _fixedPointValue >> _fractionalBits;
}

// Surcharge de l’opérateur << pour afficher la valeur en float
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

// Vérifie si le nombre courant est plus grand que l'autre
bool
Fixed::operator>(const Fixed &other) const
{
	if (this->_fixedPointValue > other._fixedPointValue)
		return true;
	return false;
}

// Vérifie si le nombre courant est plus petit que l'autre
bool
Fixed::operator<(const Fixed &other) const
{
	if (this->_fixedPointValue < other._fixedPointValue)
		return true;
	return false;
}

// Vérifie si le nombre courant est plus grand ou égal à l'autre
bool
Fixed::operator>=(const Fixed &other) const
{
	if (this->_fixedPointValue >= other._fixedPointValue)
		return true;
	return false;
}

// Vérifie si le nombre courant est plus petit ou égal à l'autre
bool
Fixed::operator<=(const Fixed &other) const
{
	if (this->_fixedPointValue <= other._fixedPointValue)
		return true;
	return false;
}

// Vérifie si le nombre courant est égal à l'autre
bool
Fixed::operator==(const Fixed &other) const
{
	if (this->_fixedPointValue == other._fixedPointValue)
		return true;
	return false;
}

// Vérifie si le nombre courant est différent de l'autre
bool
Fixed::operator!=(const Fixed &other) const
{
	if (this->_fixedPointValue != other._fixedPointValue)
		return true;
	return false;
}

// Addition de deux nombres à virgule fixe
Fixed
Fixed::operator+(const Fixed &other) const
{
	Fixed	result;
	result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
	return result;
}

// Soustraction de deux nombres à virgule fixe
Fixed
Fixed::operator-(const Fixed &other) const
{
	Fixed	result;
	result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
	return result;
}

// Multiplication de deux nombres à virgule fixe
Fixed
Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	// On multiplie les valeurs internes puis on divise par (1 << _fractionalBits)
	long long temp = (long long)this->_fixedPointValue * other._fixedPointValue;
	result.setRawBits((int)(temp >> _fractionalBits));
	return result;
}

// Division de deux nombres à virgule fixe
Fixed
Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	// On multiplie d’abord le numérateur par (1 << _fractionalBits) avant de diviser
	long long temp = ((long long)this->_fixedPointValue << _fractionalBits) / other._fixedPointValue;
	result.setRawBits((int)temp);
	return result;
}

// pré-incrémentation
Fixed
&Fixed::operator++()
{
	_fixedPointValue++; // on augmente la valeur interne d’une unité
	return *this; // on retourne l’objet lui-même (référence)
}

// post-incrémentation
Fixed
Fixed::operator++(int)
{
	Fixed	temp(*this); // on crée une copie de l'état actuel
	_fixedPointValue++; // on incrémente l’objet
	return temp; // on retourne l’état d’avant l’incrément
}

// pré-décrémentation
Fixed
&Fixed::operator--()
{
	_fixedPointValue--; // on diminue la valeur interne d’une unité
	return *this; // on retourne l’objet lui-même (référence)
}

// post-décrémentation
Fixed
Fixed::operator--(int)
{
	Fixed	temp(*this); // on crée une copie de l'état actuel
	_fixedPointValue--; // on décrémente l’objet
	return temp; // on retourne l’état d’avant le décrément
}

// retourne le plus petit des deux objets (références normales)
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

// retourne le plus petit des deux objets (références constantes)
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

// retourne le plus grand des deux objets (références normales)
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

// retourne le plus grand des deux objets (références constantes)
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

// ps : condition ? valeur_si_vrai : valeur_si_faux;
