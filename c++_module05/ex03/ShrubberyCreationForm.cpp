/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:31:32 by nippolit          #+#    #+#             */
/*   Updated: 2026/02/19 14:30:52 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <stdexcept>

// Constructeur
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

// Constructeur de recopie
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
}

// Opérateur d’affectation
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

// Destructeur
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// Méthode execute
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned())
		throw std::runtime_error("Form is not signed!");
	if (executor.getGrade() > getGradeToExecute())
		throw std::runtime_error("Bureaucrat grade too low to execute this form!");

	std::ofstream ofs(_target + "_shrubbery");
	if (!ofs)
		throw std::runtime_error("Failed to open file!");

	// Quelques arbres ASCII simples
	ofs << "       ###\n";
	ofs << "      #o###\n";
	ofs << "    #####o###\n";
	ofs << "   #o#\\#|#/###\n";
	ofs << "    ###\\|/#o#\n";
	ofs << "     # }|{  #\n";
	ofs << "       }|{\n";

	ofs.close();
}
