/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:52:48 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/23 15:53:59 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
	public:
					WrongAnimal(void);
					WrongAnimal(const WrongAnimal &other);
					WrongAnimal& operator=(const WrongAnimal &other);
					~WrongAnimal(void);

		void	makeSound(void) const;
		std::string		getType(void) const;

	protected:
		std::string	_type;
};
