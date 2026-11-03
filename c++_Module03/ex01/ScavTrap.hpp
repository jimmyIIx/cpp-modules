/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:46:27 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/22 15:49:25 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
	public:
					ScavTrap(void);
					ScavTrap(const std::string &name);
					ScavTrap(const ScavTrap &other);
					ScavTrap& operator=(const ScavTrap &other);
					~ScavTrap();

			void	attack(const std::string &target);
			void	guardGate();
};
