/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:51:50 by nippolit          #+#    #+#             */
/*   Updated: 2025/07/24 18:33:22 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	public:
				PhoneBook();
				~PhoneBook(void);
		void	add(void);
		void	search(void);
	private:
		Contact	contact_[8];
		size_t	numberContact_;
};
