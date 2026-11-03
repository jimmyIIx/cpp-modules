/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:47:49 by nippolit          #+#    #+#             */
/*   Updated: 2025/08/12 17:47:23 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cstdlib>

class 	Harl
{
	public :
						Harl(void);
						~Harl(void);
		void			complain(std::string level);
		void			harlFilter(std::string level);

	private :
		std::string		levels[4];
		void			(Harl::*HarlFunc[4])(void);
		void			debug( void );
		void			info( void );
		void			warning( void );
		void			error( void );
};
