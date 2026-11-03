/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:52:23 by nippolit          #+#    #+#             */
/*   Updated: 2025/07/23 20:00:00 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

class Contact
{
	public:
				Contact(void);
				~Contact(void);
		void	create(void);
		void	printContact(const int &index);
		void	fullPrintContact(void);

	private:
		void	readLine(const std::string &title, std::string *arg);
		std::string	format(const std::string &arg);
		std::string	firstName_;
		std::string	lastName_;
		std::string	nickname_;
		std::string	phoneNumber_;
		std::string	darkestSecret_;
};
