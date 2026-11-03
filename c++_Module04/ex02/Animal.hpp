/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:06:11 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/23 16:37:53 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal
{
	public:
					Animal(void);
					Animal(const Animal &other);
					Animal& operator=(const Animal &other);
					virtual ~Animal(void);

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;

	protected:
		std::string	_type;
};

/*

Animal (virtual)
  └── Dog
        └── vtable → makeSound() = Dog::makeSound

WrongAnimal (no virtual)
  └── WrongCat
        └── pas de vtable → makeSound() = WrongAnimal::makeSound

    Virtual → polymorphisme → résolution à l’exécution

    Non-virtual → pas de polymorphisme → résolution à la compilation


					Virtual (Animal)	Non-Virtual (WrongAnimal)
Pointeur			Animal*				WrongAnimal*
Objet réel			Dog / Cat			WrongCat
Fonction appelée	Dog::makeSound /	WrongAnimal::makeSound
					Cat::makeSound
Résolution			À l’exécution		À la compilation

*/
