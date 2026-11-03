/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:47:22 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/22 16:12:23 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// constructeur par defaut
ScavTrap::ScavTrap(void) : ClapTrap("default")
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

// contrcuteur avec nom
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

// contructeur de recopie
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "ScavTrap " << _name << " copy constructor called" << std::endl;
}

// opérateur d’affectation
ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap " << _name << " assignment operator called" << std::endl;
	return *this;
}

// destructeur
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name
			<< " cannot attack because it has no hit points left!" << std::endl;
		return;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name
			<< " cannot attack because it has no energy points left!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name
		<< " is now in Gate Keeper mode!" << std::endl;
}
