/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:21:08 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/06 19:29:23 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Weapon
{
	public:
				Weapon(void);
				Weapon(std::string type);
				~Weapon(void);

		const std::string&	getType() const;
		void				setType(const std::string& type);

	private:
		std::string		type;
};
