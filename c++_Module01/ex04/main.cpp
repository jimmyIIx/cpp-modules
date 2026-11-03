/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:46:38 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/11 22:27:50 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

static bool	setup(std::string &txt, char **argv);
static bool	rp(std::string &txt, const std::string &s1, const std::string &s2);

int	main(int argc, char **argv)
{
	std::ofstream		finish;
	std::string			txt;
	std::string			s1;
	std::string			s2;

	if (argc != 4)
		return (std::cout << "Wrong number of arguments" << std::endl, 1);

	s1 = argv[2];
	s2 = argv[3];

	if (!setup(txt, argv))
		return (std::cout << "Error: cannot open file" << std::endl, 1);

	if (!rp(txt, s1, s2))
		return 1;

	finish.open((std::string(argv[1]) + ".replace").c_str());
	if (!finish)
		return (std::cout << "Error: cannot create file" << std::endl, 1);

	finish << txt;
	return 0;
}

static bool	setup(std::string &txt, char **argv)
{
	std::ifstream		infile;
	std::ostringstream	buffer;

	infile.open(argv[1]);
	if (infile.fail())
		return false;
	buffer << infile.rdbuf();
	txt = buffer.str();
	return true;
}

static bool	rp(std::string &txt, const std::string &s1, const std::string &s2)
{
	size_t	pos = 0;

	if (s1.empty())
		return true;
	while ((pos = txt.find(s1, pos)) != std::string::npos)
	{
		txt.erase(pos, s1.length());
		txt.insert(pos, s2);
		pos += s2.length();
	}
	return true;
}
