/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:28:20 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/06 18:22:10 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";

	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "\nAdresse:" << std::endl;
	std::cout << "Adresse de str:         " << &str << std::endl;
	std::cout << "Adresse via stringPTR:  " << stringPTR << std::endl;
	std::cout << "Adresse via stringREF:  " << &stringREF << std::endl;

	std::cout << "\nValeur:" << std::endl;
	std::cout << "Valeur de str:          " << str << std::endl;
	std::cout << "Valeur via stringPTR:   " << *stringPTR << std::endl;
	std::cout << "Valeur via stringREF:   " << stringREF << std::endl;

	std::cout << std::endl;

	return 1;
}

/*
- std::string* stringPTR = &str;
je cree un pointer qui va pointer sur l'adresse de str.

- std::string& stringREF = str;
j'ouvre une deuxieme porte a la meme adresse que ptr

-- Pour stringPTR, il va pointer l'adresse de str (ligne 25),
pour montrer ce qui ce trouve dans cette adresse nous devons le deferencer
*stringPTR (ligne 30)

-- Pour stringREF, il va ce comporte comme str car c'est str sans etre une copie
Donc si on veut afficher l'adresse de stringREF il va falloir mettre '&'
ligne (26), pour afficher sa valeur voir ligne (31)

-- Pour str, fonctionne normalement comme en C et comme stringREF

/!\ Ce qui ce passe :

str > "aaaa"      > &ref = "0x484594"
ref > "aaaa"      > &ref = "0x484594"
ptr > "0x484594"  > *ptr = "aaaa"


-----------exemple avec fonction avec variable stack:

std::string str("salut");

void	exemple(std::string &str2)
envoyer str dans la fonction pour modifier le str originale
exemple(str);

void exemple(std::string *str2)
envoyer &str dans la fonction pour modifier le str original
exemple(&str)

De cette maniere str existe que dans le scop (memoire rapide de la fonction)
de la fonction sur la stack.
Ce delete tout seul a la fin de la fonction.


---------exemple avec fonction avec variable heal:

std::string *str = new std::string("salut");

void	exemple(std::string &str2)
envoyer str deferencer dans la fonction pour modifier le str originale
exemple(*str);

void exemple(std::string *str2)
envoyer str car deja pointeur dans la fonction pour modifier le str original
exemple(str)

De cette maniere str est creer sur la heap, dans la memoire (de l'ordinateur)
il faudra delete manuellement str sinon leak.

*/
