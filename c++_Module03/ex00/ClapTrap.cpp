/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:50:05 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/16 19:14:05 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// constructeur par defaut
ClapTrap::ClapTrap(void) :
	_name("default"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

// contrcuteur avec nom
ClapTrap::ClapTrap(const std::string &name) :
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

// contructeur de recopie
ClapTrap::ClapTrap(const ClapTrap &other) :
	_name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << _name << " copy constructor called" << std::endl;
}

// opérateur d’affectation
ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap " << _name << " assignment operator called" << std::endl;
	return *this;
}

// destructeur
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name
			<< " cannot attack because it has no hit points left!" << std::endl;
		return;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name
			<< " cannot attack because it has no energy points left!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
		return;
	}
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount
		<< " points of damage! Hit points left: " << _hitPoints << std::endl;
	if (this->_hitPoints < 0)
	{
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name
			<< " cannot be repaired because it has no hit points left!"
			<< std::endl;
		return;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name
			<< " cannot be repaired because it has no energy points left!"
			<< std::endl;
		return;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name
		<< " is repaired by " << amount << " points! Hit points now: "
		<< _hitPoints << std::endl;
}
