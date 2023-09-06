/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:15:35 by jrinna            #+#    #+#             */
/*   Updated: 2022/10/05 10:29:09 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

	public:

		MateriaSource();
		MateriaSource( MateriaSource const & src );
		~MateriaSource();

		MateriaSource &		operator=( MateriaSource const & rhs );
		AMateria*		getInv( int i ) const;

		void 		learnMateria( AMateria* A );
		AMateria*	createMateria( std::string const & type );

	private:

		AMateria*	_inventory[4];
};

std::ostream &			operator<<( std::ostream & o, MateriaSource const & M );
