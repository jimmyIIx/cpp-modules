/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:48:07 by nippolit          #+#    #+#             */
/*   Updated: 2026/02/19 14:31:02 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>
#include <iostream>

// Constructeur
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

// Constructeur de recopie
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target)
{
}

// Opérateur d’affectation
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other); // copie _isSigned
		_target = other._target;
	}
	return *this;
}

// Destructeur
PresidentialPardonForm::~PresidentialPardonForm()
{
}

// Méthode execute
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned())
		throw std::runtime_error("Form is not signed!");
	if (executor.getGrade() > getGradeToExecute())
		throw std::runtime_error("Bureaucrat grade too low to execute this form!");

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
