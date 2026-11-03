/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:28:49 by nippolit          #+#    #+#             */
/*   Updated: 2026/02/19 14:31:38 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public:
			explicit ShrubberyCreationForm(const std::string& target);
			ShrubberyCreationForm(const ShrubberyCreationForm& other);
			ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
			virtual ~ShrubberyCreationForm();

	// Méthode execute obligatoire
			void execute(Bureaucrat const &executor) const;

	private:
			std::string _target;
};
