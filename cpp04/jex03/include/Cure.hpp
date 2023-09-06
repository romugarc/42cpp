/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:30:54 by jrinna            #+#    #+#             */
/*   Updated: 2022/10/03 15:23:03 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Cure : public AMateria
{

	public:

		Cure();
		Cure( Cure const & src );
		~Cure();

		Cure &		operator=( Cure const & rhs );

		AMateria*	clone( void ) const;

		virtual void		use( ICharacter& target );

	private:

};

std::ostream &			operator<<( std::ostream & o, Cure const & C );
