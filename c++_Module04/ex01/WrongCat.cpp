/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:58:44 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/23 15:58:59 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructeur par défaut
WrongCat::WrongCat(void)
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
}

// Constructeur de copie
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = other;
}

// Opérateur d’affectation
WrongCat& WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

// Destructeur
WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

// makeSound() sans virtual
void WrongCat::makeSound(void) const
{
	std::cout << "Meow? (WrongCat sound!)" << std::endl;
}
