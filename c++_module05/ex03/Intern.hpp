/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:07:06 by nippolit          #+#    #+#             */
/*   Updated: 2026/02/19 14:47:37 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class AForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;
class PresidentialPardonForm;

class Intern
{
	public:
				Intern(void);
				Intern(const Intern& other);
				Intern& operator=(const Intern& other);
				~Intern(void);
				AForm* makeForm(const std::string& formName, const std::string& target) const;
	private:
};
