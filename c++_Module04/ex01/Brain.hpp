/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:06:35 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/23 16:07:24 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Brain
{
	public:
					Brain(void);
					Brain(const Brain &other);
					Brain& operator=(const Brain &other);
					~Brain(void);

		std::string	ideas[100];
};
