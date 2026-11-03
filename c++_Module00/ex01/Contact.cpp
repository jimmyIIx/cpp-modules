/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:53:14 by nippolit          #+#    #+#             */
/*   Updated: 2025/07/25 14:57:42 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void
Contact::create(void)
{
	this->readLine("first name", &this->firstName_);
	this->readLine("last name", &this->lastName_);
	this->readLine("nick name", &this->nickname_);
	this->readLine("phone number", &this->phoneNumber_);
	this->readLine("darkest secret", &this->darkestSecret_);
}

void
Contact::readLine(const std::string &title, std::string *arg)
{
	while(std::cout << "Print " << title << " > " << std::flush
			&& std::getline(std::cin, *arg) && arg->length() == 0)
	{
		continue;
	}
}

void
Contact::printContact(const int &index)
{
	std::cout
		<< std::setfill(' ') << std::setw(10) << std::left << index << " | " << std::flush
		<< this->format(this->firstName_) << " | " << std::flush
		<< this->format(this->lastName_) << " | " << std::flush
		<< this->format(this->nickname_) << std::endl;
}

std::string
Contact::format(const std::string &arg)
{
	std::stringstream	ss;
	size_t				size = arg.size() > 10 ? 9 : 10;

	ss << std::setfill(' ') << std::setw(size) << std::left
		<< arg.substr(0, size) << (size == 9 ? "." : "");
	return (ss.str());
}

void
Contact::fullPrintContact(void)
{
	std::cout << std::endl
		<< "first name:     " << this->firstName_ << std::endl
		<< "last name:      " << this->lastName_ << std::endl
		<< "nickname:       " << this->nickname_ << std::endl
		<< "phone number:   " << this->phoneNumber_ << std::endl
		<< "darkest secret: " << this->darkestSecret_ << std::endl;
}
