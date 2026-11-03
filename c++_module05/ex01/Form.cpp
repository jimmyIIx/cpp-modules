/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:09:04 by nippolit          #+#    #+#             */
/*   Updated: 2026/02/19 13:19:37 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructeur
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

// Constructeur de recopie
Form::Form(const Form& other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
}

// Opérateur d’affectation
Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

// Destructeur
Form::~Form(void)
{
}

const std::string& Form::getName() const
{
	return _name;
}

bool	Form::isSigned() const
{
	return _isSigned;
}

int	Form::getGradeToSign() const
{
	return _gradeToSign;
}

int	Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void	Form::beSigned(const Bureaucrat& signer)
{
	if (signer.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form " << f.getName()
		<< " [Signed: " << (f.isSigned() ? "Yes" : "No") << "]"
		<< ", Grade to sign: " << f.getGradeToSign()
		<< ", Grade to execute: " << f.getGradeToExecute();
	return os;
}
