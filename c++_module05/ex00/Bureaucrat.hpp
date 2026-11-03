/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:44:23 by nippolit          #+#    #+#             */
/*   Updated: 2025/12/07 13:57:39 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat
{
	public:
				Bureaucrat(void);
				Bureaucrat(const std::string& name, int grade);
				Bureaucrat(const Bureaucrat& other);
				Bureaucrat& operator=(const Bureaucrat& other);
				~Bureaucrat(void);

		const std::string&	getName() const;
		int					getGrade()const;
		void				incrementGrade();
		void				decrementGrade();

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	private:
		const std::string	_name;
		int					_grade;
};

	std::ostream&	operator<<(std::ostream& os, const Bureaucrat& x);
