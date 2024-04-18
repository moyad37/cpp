#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <string>
#include <iostream>

class Animal
{	
	public:
		Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal& copy);
		
		std::string const& getType(void) const;
		virtual void makeSound() const;
		virtual ~Animal();

	protected:
		std::string type;
		
};

#endif
