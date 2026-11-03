/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:46:18 by nippolit          #+#    #+#             */
/*   Updated: 2026/02/19 14:23:25 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
		public:
				explicit PresidentialPardonForm(const std::string& target);
				PresidentialPardonForm(const PresidentialPardonForm& other);
				PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
				virtual ~PresidentialPardonForm();

				// Méthode execute obligatoire
				void	execute(Bureaucrat const &executor) const;

		private:
				std::string _target;
};
