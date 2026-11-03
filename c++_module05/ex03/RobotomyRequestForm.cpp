/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:37:29 by nippolit          #+#    #+#             */
/*   Updated: 2026/02/19 14:30:56 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>    // pour rand()
#include <ctime>      // pour srand()
#include <stdexcept>
#include <iostream>

// Constructeur
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::srand(std::time(nullptr)); // initialisation du random
}

// Constructeur de recopie
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target)
{
}

// Opérateur d’affectation
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

// Destructeur
RobotomyRequestForm::~RobotomyRequestForm()
{
}

// Méthode execute
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned())
		throw std::runtime_error("Form is not signed!");
	if (executor.getGrade() > getGradeToExecute())
		throw std::runtime_error("Bureaucrat grade too low to execute this form!");

	std::cout << "Drilling noises... BzzzZZZzzz..." << std::endl;

	// 50% de chance de réussite
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << std::endl;
}
