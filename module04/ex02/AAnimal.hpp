#ifndef AAnimal_HPP
#define AAnimal_HPP


#include <string>
#include <iostream>
#include "Brain.hpp"

class AAnimal
{	
	protected:
		AAnimal();
		AAnimal(const AAnimal& copy);
		AAnimal& operator=(const AAnimal& copy);
		
		virtual ~AAnimal();
		std::string type;

	public:
		std::string const& getType(void) const;
		virtual void makeSound() const = 0;
		
};

#endif
