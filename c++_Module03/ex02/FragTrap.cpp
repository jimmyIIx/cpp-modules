/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:18:33 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/22 16:26:13 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// constructeur par defaut
FragTrap::FragTrap(void) : ClapTrap("default")
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

// contrcuteur avec nom
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

// contructeur de recopie
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap " << _name << " copy constructor called" << std::endl;
}

// opérateur d’affectation
FragTrap& FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap " << _name << " assignment operator called" << std::endl;
	return *this;
}

// destructeur
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "FragTrap " << _name
			<< " cannot attack because it has no hit points left!" << std::endl;
		return;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "FragTrap " << _name
			<< " cannot attack because it has no energy points left!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "FragTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name
		<< " requests a positive high five!" << std::endl;
}
