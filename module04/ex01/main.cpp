#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define MAX_ANIMALS 2

int main( void )
{
	Animal* animals[MAX_ANIMALS];
	for (int i = 0; i < MAX_ANIMALS; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	if (MAX_ANIMALS > 0)
	{
		Animal* copy = new Dog(*(Dog *)animals[0]);
		std::cout << copy->getType() << std::endl;
		copy->makeSound();
		delete copy;
	}

	for (int i = 0; i < MAX_ANIMALS; i++)
	{
		delete animals[i];
	}

	// {
    // 	Dog basic;
	// 	Dog tmp = basic;
	// }

	// {
    // 	const Animal* animals[] = { new Dog(), new Dog(), new Cat(), new Cat(), new Cat(), new Dog() };
	// 	size_t numElements = sizeof(animals) / sizeof(animals[0]);
    // 	for ( size_t i = 0; i < numElements; i++ ) {
	// 		delete animals[i];
    // 	}
	// }

    return 0;
}
