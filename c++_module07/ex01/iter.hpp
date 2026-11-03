/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:29:54 by nippolit          #+#    #+#             */
/*   Updated: 2025/10/31 16:36:13 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstddef>
#include <string>

template <typename T, typename F>
void	iter(T *array, size_t length, F func)
{
	if (!array || !func)
		return;
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T, typename F>
void	iter(T const *array, size_t const length, F func)
{
	if (!array)
		return;
	for (size_t i = 0; i < length; i++)
		func(array[i]);
};
