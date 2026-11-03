/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:42:55 by nippolit          #+#    #+#             */
/*   Updated: 2025/10/27 16:26:26 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

// Fonction swap
template <typename T>
void	swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

// Fonction min
template <typename T>
T const & min(T const & a, T const & b)
{
	return (a < b ? a : b); // si égaux, retourne b selon le sujet, ternaire
}

// Fonction max
template <typename T>
T const & max(T const & a, T const & b)
{
	return (b < a ? a : b); // si égaux, retourne b, ternaire
}
