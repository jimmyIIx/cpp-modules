/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:47:46 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/12 17:41:51 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// contructeur default
Harl::Harl(void)
{

	this->HarlFunc[0] = &Harl::debug;
	this->HarlFunc[1] = &Harl::info;
	this->HarlFunc[2] = &Harl::warning;
	this->HarlFunc[3] = &Harl::error;

	this->levels[0] = "DEBUG";
	this->levels[1] = "INFO";
	this->levels[2] = "WARNING";
	this->levels[3] = "ERROR";
}


// destructeur
Harl::~Harl(void)
{
}

void
Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->levels[i] == level)
			return ((this->*HarlFunc[i])());
	}
}

void
Harl::debug(void)
{
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!" << std::endl;
}

void
Harl::info(void)
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!" << std::endl;
}

void
Harl::warning(void)
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
}

void
Harl::error(void)
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}
