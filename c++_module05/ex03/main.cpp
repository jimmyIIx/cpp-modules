/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:36:45 by nippolit          #+#    #+#             */
/*   Updated: 2025/10/31 17:20:00 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "\n";
	try
	{
		// ----- Création de bureaucrats -----
		std::cout << "--- BUREAUCRATS ---\n";

		Bureaucrat john("John", 50);
		Bureaucrat alice("Alice", 1);
		Bureaucrat bob("Bob", 150);

		std::cout << john << std::endl;
		std::cout << alice << std::endl;
		std::cout << bob << std::endl;

		std::cout << "\n-----------------------------\n\n";

		// ----- Création des forms -----
		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Marvin");

		// ----- TEST SIGNATURE -----
		std::cout << "--- TEST SIGNATURE ---\n";

		std::cout << "[John tries to sign Shrubbery] -> ";
		john.signForm(shrub);    // devrait réussir

		std::cout << "[John tries to sign Robotomy] -> ";
		john.signForm(robot);    // devrait échouer

		std::cout << "[John tries to sign Pardon] -> ";
		john.signForm(pardon);   // devrait échouer

		std::cout << "[Bob tries to sign Shrubbery] -> ";
		bob.signForm(shrub);     // devrait échouer

		std::cout << "[Alice tries to sign Robotomy] -> ";
		alice.signForm(robot);   // succès

		std::cout << "[Alice tries to sign Pardon] -> ";
		alice.signForm(pardon);  // succès

		// Affichage des forms
		std::cout << "\n--- FORMS STATUS AFTER SIGNATURES ---\n";
		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;

		std::cout << "\n-----------------------------\n\n";

		// ----- TEST EXECUTION -----
		std::cout << "--- TEST EXECUTION ---\n";

		std::cout << "[Bob tries to execute Shrubbery] -> ";
		try
		{
			bob.executeForm(shrub);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Bob cannot execute: " << e.what() << std::endl;
		}

		std::cout << "[John tries to execute Robotomy] -> ";
		try
		{
			john.executeForm(robot);
		}
		catch (const std::exception& e)
		{
			std::cerr << "John cannot execute: " << e.what() << std::endl;
		}

		std::cout << "[Alice executes Shrubbery] -> ";
		shrub.execute(alice);

		std::cout << "[Alice executes Robotomy] -> ";
		robot.execute(alice);

		std::cout << "[Alice executes Pardon] -> ";
		pardon.execute(alice);

		std::cout << "[Try to execute unsigned form] -> ";
		ShrubberyCreationForm temp("garden");
		try
		{
			temp.execute(alice);
		}
		catch (const std::exception& e)
		{
			std::cerr << "Cannot execute unsigned form: " << e.what() << std::endl;
		}

		std::cout << "\n-----------------------------\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}

	// ----- TEST INTERN -----
	std::cout << "\n--- TEST INTERN ---\n";
	Intern someRandomIntern;
	AForm* form1 = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm* form2 = someRandomIntern.makeForm("shrubbery creation", "home");
	AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Marvin");
	AForm* form4 = someRandomIntern.makeForm("unknown form", "Nobody"); // test erreur

	if (form1)
	{
		delete form1;
	}
	if (form2)
	{
		delete form2;
	}
	if (form3)
	{
		delete form3;
	}
	if (form4)
	{
		delete form4;
	}
	return 0;
}
