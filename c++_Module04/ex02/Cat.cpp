/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:49:11 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/23 16:16:12 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructeur par défaut
Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

// Constructeur de copie
Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*other._brain); // copie profonde du Brain
	*this = other;
}

// Opérateur d’affectation
Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
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
Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain; // libère la mémoire
}

// makeSound()
void Cat::makeSound(void) const
{
	std::cout << "Meow! Meow!" << std::endl;
}
