/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:28:47 by nippolit          #+#    #+#             */
/*   Updated: 2025/10/31 17:55:37 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	srand(time(NULL));

	Base* obj = generate();

	std::cout << "Identify via pointer: ";
	identify(obj);

	std::cout << "Identify via reference: ";
	identify(*obj);

	delete obj;
	return (0);
}
