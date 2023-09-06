/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:13:53 by jrinna            #+#    #+#             */
/*   Updated: 2022/10/05 10:18:43 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include "AMateria.hpp"

class IMateriaSource
{

	public:

		virtual ~IMateriaSource() {}
		virtual void learnMateria( AMateria* A ) = 0;
		virtual AMateria* createMateria( std::string const & type ) = 0;

};
