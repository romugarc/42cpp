#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	const Animal* doga = new Dog();
	const Animal* dogb(doga);
	const Animal* dogc = dogb;

	const Animal* cata = new Cat();
	const Animal* catb(cata);
	const Animal* catc = catb;

	return 0;
}