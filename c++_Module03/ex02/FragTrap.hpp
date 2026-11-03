/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:18:19 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/22 16:21:14 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
	public:
					FragTrap(void);
					FragTrap(const std::string &name);
					FragTrap(const FragTrap &other);
					FragTrap& operator=(const FragTrap &other);
					~FragTrap();

			void	attack(const std::string &target);
			void	highFivesGuys(void);
};
