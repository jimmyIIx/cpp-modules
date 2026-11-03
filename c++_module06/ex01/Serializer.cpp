/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:16:53 by nippolit          #+#    #+#             */
/*   Updated: 2025/10/27 15:19:37 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

// constructeur par defaut
Serializer::Serializer(void)
{
}

// contructeur de recopie
Serializer::Serializer(const Serializer& other)
{
	(void)other;
}

// opérateur d’affectation
Serializer& Serializer::operator=(const Serializer& other)
{
	return *this;
}

// destructeur
Serializer::~Serializer(void)
{
}

// convertit un pointeur en entier
uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

// convertit un entier en pointeur
Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
