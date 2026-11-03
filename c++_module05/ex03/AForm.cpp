/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:09:04 by nippolit          #+#    #+#             */
/*   Updated: 2026/02/19 14:30:04 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructeur
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

// Constructeur de recopie
AForm::AForm(const AForm& other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
}

// Opérateur d’affectation
AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

// Destructeur
AForm::~AForm(void)
{
}

const std::string& AForm::getName() const
{
	return _name;
}

bool	AForm::isSigned() const
{
	return _isSigned;
}

int	AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int	AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "AForm " << f.getName()
		<< " [Signed: " << (f.isSigned() ? "Yes" : "No") << "]"
		<< ", Grade to sign: " << f.getGradeToSign()
		<< ", Grade to execute: " << f.getGradeToExecute();
	return os;
}
