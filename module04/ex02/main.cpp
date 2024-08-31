
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "AAnimal.hpp"
#define MAX_ANIMALS 2



int main( void )
{


// 	AAnimal* animals[MAX_ANIMALS];
// 	for (int i = 0; i < MAX_ANIMALS; i++)
// 	{
// 		if (i % 2 == 0)
// 			animals[i] = new Dog();
// 		else
// 			animals[i] = new Cat();
// 	}

// 	if (MAX_ANIMALS > 0)
// 	{
// 		AAnimal* copy = new Dog(*(Dog *)animals[0]);
// 		std::cout << copy->getType() << std::endl;
// 		copy->makeSound();
// 		delete copy;
// 	}

// 	for (int i = 0; i < MAX_ANIMALS; i++)
// 	{
// 		delete animals[i];
// 	}


// 	// Pointer tests (Polymorphic)
// 	std::cout << "\033[1;34mPointer tests (Polymorphic)\033[0m" << std::endl;
// 	const AAnimal* j = new Dog();
// 	const AAnimal* i = new Cat();
// 	// std::cout << "\033[#####################################\033[0m" << std::endl;
// 	// const AAnimal* k;
// 	// const AAnimal* d(k);
// 	// std::cout << "\033#######################################\033[0m" << std::endl;
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();

// 	// Reference tests (Polymorphic)
// 	std::cout << "\033[1;34mReference tests (Polymorphic)\033[0m" << std::endl;
// 	const AAnimal& l = *j;
// 	const AAnimal& m = *i;

// 	std::cout << l.getType() << " " << std::endl;
// 	std::cout << m.getType() << " " << std::endl;
// 	m.makeSound();
// 	l.makeSound();

// 	delete j;
// 	delete i;
// 	// {
//     // 	const AAnimal* j = new Dog();
//     // 	const AAnimal* i = new Cat();
//     // 	delete j;//should not create a leak
//     // 	delete i;
// 	// }

// 	// {
//     // 	Dog basic;
// 	// 	Dog tmp = basic;
// 	// }

// 	// {
//     // 	const AAnimal* animals[] = { new Dog(), new Dog(), new Cat(), new Cat(), new Cat(), new Dog() };
// 	// 	size_t numElements = sizeof(animals) / sizeof(animals[0]);
//     // 	for ( size_t i = 0; i < numElements; i++ ) {
// 	// 		delete animals[i];
//     // 	}
// 	// }

     return 0;
}
