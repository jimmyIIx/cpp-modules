/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:06:14 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/23 15:49:43 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include <iostream>
#include <string>

class Cat : public Animal
{
	public:
					Cat(void);
					Cat(const Cat &other);
					Cat& operator=(const Cat &other);
					virtual ~Cat(void);
		void 		makeSound(void) const;
};
