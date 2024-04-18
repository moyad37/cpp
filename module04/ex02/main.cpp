
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "AAnimal.hpp"

int main( void )
{
	
	{
    	const AAnimal* j = new Dog();
    	const AAnimal* i = new Cat();

    	delete j;//should not create a leak
    	delete i;
	}

	{
    	Dog basic;
		Dog tmp = basic;
	}

	{
    	const AAnimal* animals[] = { new Dog(), new Dog(), new Cat(), new Cat(), new Cat(), new Dog() };
		size_t numElements = sizeof(animals) / sizeof(animals[0]);
    	for ( size_t i = 0; i < numElements; i++ ) {
			delete animals[i];
    	}
	}

    return 0;
}
