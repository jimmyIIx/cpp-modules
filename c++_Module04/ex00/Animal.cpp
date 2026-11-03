/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:11:06 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/23 15:44:00 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// constructeur par defaut
Animal::Animal(void) :
	_type("animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

// contructeur de recopie
Animal::Animal(const Animal &other) :
	_type(other._type)
{
	std::cout << "Animal " << _type << " copy constructor called" << std::endl;
}

// opérateur d’affectation
Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	std::cout << "Animal " << _type << " assignment operator called" << std::endl;
	return *this;
}

// destructeur
Animal::~Animal(void)
{
	std::cout << "Animal " << _type << " destructor called" << std::endl;
}

void
Animal::makeSound(void) const
{
	std::cout << "Animal " << _type << " makes a sound!" << std::endl;
}

std::string Animal::getType(void) const
{
	return _type;
}
