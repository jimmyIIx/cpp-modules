/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:22:30 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/06 19:36:58 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	public:
				HumanB(void);
				HumanB(std::string name);
				~HumanB(void);

		void			attack();
		void			setWeapon(Weapon& arme);

	private:
		std::string		name;
		Weapon*			arme;
};
