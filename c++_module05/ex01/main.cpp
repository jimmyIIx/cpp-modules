/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:36:45 by nippolit          #+#    #+#             */
/*   Updated: 2025/09/16 18:39:23 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "\n>>> Test <<<\n" << std::endl;

	std::cout << "=== Bureaucrat normal pour signer ok ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 2);
		Form form1("Form A", 2, 50);

		std::cout << bob << std::endl;
		std::cout << form1 << std::endl;

		std::cout << "\nBob tente de signer Form A" << std::endl;
		bob.signForm(form1);
		std::cout << form1 << std::endl;
	}
	catch (const std::exception& err)
	{
		std::cerr << "Exception : " << err.what() << std::endl;
	}

	std::cout << "\n=== Bureaucrat trop bas pour signer ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 50);
		Form form2("Form B", 30, 100);

		std::cout << alice << std::endl;
		std::cout << form2 << std::endl;

		std::cout << "\nAlice tente de signer Form B" << std::endl;
		alice.signForm(form2); // devrait lancer Form::GradeTooLowException
		std::cout << form2 << std::endl;
	}
	catch (const std::exception& err)
	{
		std::cerr << "Exception : " << err.what() << std::endl;
	}

	std::cout << "\n=== Formulaire invalide trop haut ===" << std::endl;
	try
	{
		Form invalidForm("Form Invalid", 0, 10);
	}
	catch (const std::exception& err)
	{
		std::cerr << "Exception : " << err.what() << std::endl;
	}

	std::cout << "\n=== Formulaire invalide trop bas ===" << std::endl;
	try
	{
		Form invalidForm2("Form Invalid2", 10, 200);
	}
	catch (const std::exception& err)
	{
		std::cerr << "Exception : " << err.what() << std::endl;
	}

	return (0);
}
