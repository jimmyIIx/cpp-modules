/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:27:30 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/23 16:28:26 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main(void)
{
	const int SIZE = 4; // taille du tableau, exemple 4 animaux
	Animal* zoo[SIZE];

	std::cout << "=== Création des animaux ===" << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (i < SIZE / 2)
			zoo[i] = new Dog();
		else
			zoo[i] = new Cat();
	}

	std::cout << "\n=== Sons des animaux ===" << std::endl;
	for (int i = 0; i < SIZE; i++)
		zoo[i]->makeSound();

	std::cout << "\n=== Destruction des animaux ===" << std::endl;
	for (int i = 0; i < SIZE; i++)
		delete zoo[i];

	return 0;
}
