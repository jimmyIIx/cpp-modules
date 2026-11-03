/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:44:34 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/23 16:17:49 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructeur par défaut
Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

// Constructeur de copie
Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*other._brain); // copie profonde du Brain
	*this = other;
}

// Opérateur d’affectation
Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*other._brain); // copie profonde du Brain
	}
	return (*this);
}

// Destructeur
Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain; // libère la mémoire
}

// makeSound()
void Dog::makeSound(void) const
{
	std::cout << "Woof! Woof!" << std::endl;
}
