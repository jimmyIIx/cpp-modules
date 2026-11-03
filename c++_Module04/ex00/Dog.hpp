/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:06:17 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/23 15:44:07 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include <iostream>
#include <string>

class Dog : public Animal
{
	public:
					Dog(void);
					Dog(const Dog &other);
					Dog& operator=(const Dog &other);
					virtual ~Dog(void);
		void 		makeSound(void) const;
};
