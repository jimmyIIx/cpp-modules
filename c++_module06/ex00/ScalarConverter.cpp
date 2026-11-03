/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:49:17 by nippolit          #+#    #+#             */
/*   Updated: 2026/02/21 15:37:40 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// constructeur par defaut
ScalarConverter::ScalarConverter(void)
{
}

// contructeur de recopie
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

// opérateur d’affectation
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

// destructeur
ScalarConverter::~ScalarConverter(void)
{
}

void	ScalarConverter::convert(std::string const &literal)
{
	std::cout << "Conversion demandée pour : " << literal << std::endl;

	enum Type {CHAR, INT, FLOAT, DOUBLE, PSEUDO, UNKNOW};
	Type type = UNKNOW;

	if (literal == "nan" || literal == "nanf" ||
		literal == "+inf" || literal == "-inf" ||
		literal == "+inff" || literal == "-inff")
	{
		type = PSEUDO;
	}
	else if (literal.length() == 1 && !isdigit(literal[0]))
	{
		type = CHAR;
	}
	else
	{
		bool point = false;
		bool F = false;
		bool valide = true;

		for (size_t i = 0; i < literal.length(); ++i)
		{
			if (literal[i] == '.')
				point = true;
			else if (literal[i] == 'f' && i == literal.length() - 1)
				F = true;
			else if (!isdigit(literal[i]) && !(i == 0 && (literal[i] == '-' || literal[i] == '+')))
				valide = false;
		}
		if (!valide)
			type = UNKNOW;
		else if (point && F)
			type = FLOAT;
		else if (point && !F)
			type = DOUBLE;
		else if (!point && !F)
			type = INT;
	}
	if (type == CHAR)
	{
		// convertit
		char c = literal[0];
		int i = static_cast<int>(c);
		float f = static_cast<float>(c);
		double d = static_cast<double>(c);

		// affichage
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else if (type == INT)
	{
		// convertit
		int i = std::atoi(literal.c_str());
		char c = static_cast<char>(i);
		float f = static_cast<float>(i);
		double d = static_cast<double>(i);

		// affichage
		if (isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else if (type == FLOAT)
	{
		// convertit
		float f = static_cast<float>(std::atof(literal.c_str()));
		char c = static_cast<char>(f);
		int i = static_cast<int>(f);
		double d = static_cast<double>(f);

		// affichage
		if (isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else if (type == DOUBLE)
	{
		// convertit
		double d = std::atof(literal.c_str());
		char c = static_cast<char>(d);
		int i = static_cast<int>(d);
		float f = static_cast<float>(d);

		// affichage
		if (isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else if (type == PSEUDO)
	{
		// char et int impossibles
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;

		// float et double
		if (literal.back() == 'f')
		{
			std::cout << "float: " << literal << std::endl;
			std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
		}
		else
		{
			std::cout << "float: " << literal << "f" << std::endl;
			std::cout << "double: " << literal << std::endl;
		}
	}
	else if (type == UNKNOW)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
