/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:36:15 by nippolit          #+#    #+#             */
/*   Updated: 2026/02/19 14:31:33 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
		public:
				explicit RobotomyRequestForm(const std::string& target);
				RobotomyRequestForm(const RobotomyRequestForm& other);
				RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
				virtual ~RobotomyRequestForm();

				// Méthode execute obligatoire
				void	execute(Bureaucrat const &executor) const;

		private:
				std::string _target;
};
