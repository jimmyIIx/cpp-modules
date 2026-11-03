/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:57:54 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/23 15:58:27 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal
{
	public:
					WrongCat(void);
					WrongCat(const WrongCat &other);
					WrongCat& operator=(const WrongCat &other);
					~WrongCat(void);

		void		makeSound(void) const;
};
