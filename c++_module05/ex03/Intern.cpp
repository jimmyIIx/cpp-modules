/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:07:09 by nippolit          #+#    #+#             */
/*   Updated: 2026/02/19 14:47:30 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Constructeur
Intern::Intern(void)
{
}

// Constructeur de recopie
Intern::Intern(const Intern& other)
{
	(void)other;
}

// Opérateur d’affectation
Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

// Destructeur
Intern::~Intern(void)
{
}

// Structure pour creation
typedef struct s_formPair
{
	std::string name;
	AForm* (*createFunc)(const std::string& target);
}t_formPair;

// Fonctions de création formulaire
static AForm* createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	t_formPair forms[] =
	{
		{"shrubbery creation", &createShrubbery},
		{"robotomy request", &createRobotomy},
		{"presidential pardon", &createPresidential}
	};

	for (size_t i = 0; i < 3; ++i)
	{
		if (forms[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].createFunc(target);
		}
	}
	std::cerr << "Intern cannot create \"" << formName << "\": unknown form" << std::endl;
	return nullptr;
}
