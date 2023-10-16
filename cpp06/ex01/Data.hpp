#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <stdint.h>

class Data
{
    private:
        std::string const _realdata;
        double  const _numdata;
	public:
		Data( void );
		Data( Data const &src );
		~Data();

		Data &operator=( Data const &rhs );

        std::string getReal( void ) const;
        double  getNum( void ) const;
};

#endif