/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:58:07 by jrinna            #+#    #+#             */
/*   Updated: 2022/10/04 11:20:35 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include "ICharacter.hpp"

using std::cout;
using std::endl;
using std::string;

class ICharacter;

class AMateria
{

	public:

		AMateria();
		AMateria( AMateria const & src );
		AMateria( string const & type );
		virtual ~AMateria();

		AMateria &			operator=( AMateria const & rhs );

		string	const &		getType( void ) const;

		virtual AMateria*	clone() const = 0;
		virtual void		use( ICharacter& target );

	protected:

		string	_type;

};

std::ostream &			operator<<( std::ostream & o, AMateria const & A );
