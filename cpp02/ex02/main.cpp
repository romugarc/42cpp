#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	//Tests supplémentaires
	Fixed a;
    /*std::cout << "////////////////////////////////////////////////////////////////" << std::endl;
    std::cout << " Tests arithm :" << std::endl;
    std::cout << "/////////////////" << std::endl << std::endl;

    Fixed a;
    Fixed const b(Fixed(40) + Fixed(0.42f) + Fixed(2));
    std::cout << "Test : addition + multi stage + addition floats and int :" << std::endl;
    std::cout << "b = 40 + 0.42 + 2 = " << b << std::endl << std::endl;

    std::cout << "Test : b - b" << std::endl;
    Fixed const c(Fixed(b) - b);
    std::cout << c << std::endl << std::endl;

    std::cout << "Test : b * 2" << std::endl;
    Fixed const d(Fixed(b) * 2);
    std::cout << d << std::endl << std::endl;

    std::cout << "Test : b / 10" << std::endl;
    Fixed const e(Fixed(b) / 10);
    std::cout << e << std::endl << std::endl;
	std::cout << "Test : f = b * 10 - 2" << std::endl;
    Fixed f((Fixed(b) * Fixed(10) - Fixed(2)));
    std::cout << "f = " << f << std::endl << std::endl;

    f = f / Fixed(10) + Fixed(400);
    std::cout << "Test : f = f / 10 + 400" << std::endl;
    std::cout << " f = " << f << std::endl << std::endl;

	std::cout << "////////////////////////////////////////////////////////////////" << std::endl;
    std::cout << " Tests comparison :" << std::endl;
    std::cout << "/////////////////" << std::endl << std::endl;

    std::cout << "B = " << b << std::endl << std::endl;

    std::cout << "Test : b == b" << std::endl;
    std::cout << (b == b) << std::endl << std::endl;

    std::cout << "Test : b != b" << std::endl;
    std::cout << (b != b) << std::endl << std::endl;

    std::cout << "Test : 42 <= b" << std::endl;
    std::cout << (Fixed(42) <= b) << std::endl << std::endl;

    std::cout << "Test : 42 >= b" << std::endl;
    std::cout << (Fixed(42) >= b) << std::endl << std::endl;

    std::cout << "Test : b < 42" << std::endl;
    std::cout << (b < Fixed(42)) << std::endl << std::endl;

    std::cout << "Test : b > 42" << std::endl;
    std::cout << (b > Fixed(42)) << std::endl << std::endl;

	std::cout << "////////////////////////////////////////////////////////////////" << std::endl;
    std::cout << " Tests increment & decrement : Pre and Post form :" << std::endl;
    std::cout << "//////////////////////////////////////////////////" << std::endl << std::endl;

    std::cout << "//////////////////Increment/////////////////////////" << std::endl ;
    Fixed w;
    a = Fixed(21.21f);
    std::cout << "a = " << a << std::endl << std::endl;

    std::cout << "Test : w = ++a" << std::endl;
    w = ++a;
    std::cout << "w = "<< w << qjoj << qq << std::endl;
    std::cout << "a = "<< a << std::endl << std::endl;

    std::cout << "Test : w = a++" << std::endl;
    w = a++;
    std::cout << "w = "<< w << std::endl;
    std::cout << "a = "<< a << std::endl << std::endl;

	std::cout << "//////////////////Decrement/////////////////////////" << std::endl;
    std::cout << "a = " << a << std::endl << std::endl;

    std::cout << "Test : w = --a" << std::endl;
    w = --a;
    std::cout << "w = "<< w << std::endl;
    std::cout << "a = "<< a << std::endl << std::endl;

    std::cout << "Test : w = a--" << std::endl;
    w = a--;
    std::cout << "w = "<< w << std::endl;
    std::cout << "a = "<< a << std::endl << std::endl;

	std::cout << "////////////////////////////////////////////////////////////////" << std::endl;
    std::cout << " Test min() max() functions:" << std::endl;
    std::cout << "////////////////////////////" << std::endl << std::endl;

    Fixed const a_c(a);
    Fixed const w_c(w);
    a = Fixed(21.21f);

    std::cout << "a = " << a << std::endl;
    std::cout << "w = " << w << std::endl << std::endl;
    std::cout << "(constant a) a_c = " << a_c << std::endl;
    std::cout << "(constant w) w_c = " << w_c << std::endl << std::endl;

    std::cout << "//////////////////Min/////////////////////////" << std::endl << std::endl;

    std::cout << "Test with argument : " << "a.min(a, w) = " << a.min(a, w) << std::endl;
    std::cout << "Test with const argument : " << "a.min(a_c,w_c) = " << a.min(a_c,w_c) << std::endl << std::endl;

    std::cout << "//////////////////Max/////////////////////////" << std::endl << std::endl;


    std::cout << "Test with argument : " << "a.max(a, w) = " << a.max(a, w) << std::endl;
    std::cout << "Test with const argument : " << "a.max(a_c,w_c) = " << a.max(a_c,w_c) << std::endl << std::endl;*/
	return 0;
}