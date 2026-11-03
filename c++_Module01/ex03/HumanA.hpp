/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:22:35 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/12 16:54:27 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	public:
				HumanA(void);
				HumanA(std::string name, Weapon& arme);
				~HumanA(void);

		void	attack();


	private:
		std::string		name;
		Weapon*			arme;
};
