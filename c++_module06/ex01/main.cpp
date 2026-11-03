/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:21:19 by nippolit          #+#    #+#             */
/*   Updated: 2025/10/27 15:30:24 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	// Création d'un objet Data
	Data original;
	original.n = 42;
	original.str = "Hello";

	// Sérialisation : convertir le pointeur en entier
	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Adresse sérialisée : " << raw << std::endl;

	// Désérialisation : convertir l'entier en pointeur
	Data* ptr = Serializer::deserialize(raw);

	// Vérification
	std::cout << "Adresse originale : " << &original << std::endl;
	std::cout << "Adresse désérialisée : " << ptr << std::endl;

	// Vérification des valeurs
	if (ptr)
	{
		std::cout << "n = " << ptr->n << ", str = " << ptr->str << std::endl;
	}

	return (0);
}
