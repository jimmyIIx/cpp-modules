/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:55:22 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/23 15:57:18 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructeur par défaut
WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

// Constructeur de copie
WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

// Opérateur d’affectation
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		_type = other._type;
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	return *this;
}

// Destructeur
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

// makeSound()
void
WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal makes a generic sound!" << std::endl;
}

// getType()
std::string WrongAnimal::getType(void) const
{
	return _type;
}
