/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:52:59 by nippolit          #+#    #+#             */
/*   Updated: 2025/07/24 19:42:53 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) :
	numberContact_(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

void
PhoneBook::add(void)
{
	int index = this->numberContact_ % 8;
	this->contact_[index].create();
	++this->numberContact_;
}

void
PhoneBook::search(void)
{
	std::string	input;

	std::cout << std::endl
		<< std::setfill(' ') << std::setw(11) << std::left << "index" << std::flush
		<< std::setfill(' ') << std::setw(13) << std::left << "first name" << std::flush
		<< std::setfill(' ') << std::setw(13) << std::left << "last name" << std::flush
		<< std::setfill(' ') << std::setw(12) << std::left << "nickname" << std::endl
		<< std::setfill('-') << std::setw(49) << "-"  << std::endl;
	for(int index = 0; index < 8; ++index)
	{
		this->contact_[index].printContact(index);
	}
	std::cout << std::endl;
	while (std::cout << "What #id do you want to see (0-7): " << std::flush
			&& std::getline(std::cin, input) && (input.size() != 1 || input[0] < '0' || input[0] > '7'))
		continue;
	this->contact_[input[0] - '0'].fullPrintContact();
}
