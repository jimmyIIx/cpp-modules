/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:36:24 by nippolit          #+#    #+#             */
/*   Updated: 2025/12/06 14:28:14 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "\n>>> Test <<<\n" << std::endl;

	std::cout << "=== grade normal et incrémente ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;
		std::cout << "incrémente Bob" << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;
	}
	catch(const std::exception& err)
	{
		std::cerr << "Exception : " << err.what() << std::endl;
	}

	std::cout << "\n=== grade bas et décrémente ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 150);
		std::cout << alice << std::endl;
		std::cout << "décrémente Alice" << std::endl;
		alice.decrementGrade();
		std::cout << alice << std::endl;
	}
	catch(const std::exception& err)
	{
		std::cerr << "Exception : " << err.what() << std::endl;
	}

	std::cout << "\n=== bureaucrat grade trop haut ===" << std::endl;
	try
	{
		std::cout << "creation de invalid1 grade 0" << std::endl;
		Bureaucrat invalid1("Invalid1", 0);
	}
	catch (const std::exception& err)
	{
		std::cerr << "Exception : " << err.what() << std::endl;
	}

	std::cout << "\n=== bureaucrat grade grade trop bas ===" << std::endl;
	try
	{
		std::cout << "creation de invalid2 grade 200" << std::endl;
		Bureaucrat invalid2("Invalid2", 200);
	}
	catch (const std::exception& err)
	{
		std::cerr << "Exception : " << err.what() << std::endl;
	}

	return (0);
}


/*
modéliser un bureaucrate avec des caractéristiques et des comportements,
gérer les erreurs si quelqu’un essaie de tricher avec ces règles.

- Un bureaucrate a un nom (qui ne change jamais) et un grade (un nombre entre 1 et 150).
- Plus le grade est bas plus il est important.
- créer un bureaucrate avec un grade hors limite = lancer exeption
*/
