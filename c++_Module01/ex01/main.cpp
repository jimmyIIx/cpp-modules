/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:40:21 by nippolit          #+#    #+#             */
/*   Updated: 2025/07/25 17:33:22 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie*
zombieHorde(int N, std::string name);

int main(void)
{
	int size = 5;

	Zombie *horde = zombieHorde(size, "bob");
	for (int i = 0; i < size; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}
