#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <time.h>

class Base
{
	public:
		virtual ~Base() {};
};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};

Base    *generate ( void ) {
	std::srand(time(0));
	int i = std::rand();

	if ( i % 3 == 1 )
		return (new A);
	else if ( i % 3 == 2 )
		return (new B);
	else
		return (new C);
}

void	identify( Base *p ) {
	A   *a = dynamic_cast<A *>(p);
	B   *b = dynamic_cast<B *>(p);
	C   *c = dynamic_cast<C *>(p);

	if (a)
		std::cout << "p is of class A" << std::endl;
	if (b)
		std::cout << "p is of class B" << std::endl;
	if (c)
		std::cout << "p is of class C" << std::endl;
}

void	identify( Base &p ) {
	try
	{
		A   &a = dynamic_cast<A &>(p);
		(void)a;
	}
	catch(const std::exception& e)
	{
		std::cout << "p can't be of class A" << std::endl;
	}

	try
	{
		B   &b = dynamic_cast<B &>(p);
		(void)b;
	}
	catch(const std::exception& e)
	{
		std::cout << "p can't be of class B" << std::endl;
	}

	try
	{
		C   &c = dynamic_cast<C&>(p);
		(void)c;
	}
	catch(const std::exception& e)
	{
		std::cout << "p can't be of class C" << std::endl;
	}
}

#endif