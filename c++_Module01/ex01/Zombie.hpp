/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:40:49 by nippolit          #+#    #+#             */
/*   Updated: 2025/07/25 17:01:53 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Zombie
{
	public:
			Zombie(std::string name);
			Zombie(void);
			~Zombie(void);
	void	announce(void);
	void	setupName(std::string name);


	private:
		std::string		name;
};
