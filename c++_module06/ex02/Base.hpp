/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:29:27 by nippolit          #+#    #+#             */
/*   Updated: 2025/10/31 17:47:57 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>

class Base
{
		public:
				 virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*	generate(void);

void	identify(Base* p);
void	identify(Base& p);
