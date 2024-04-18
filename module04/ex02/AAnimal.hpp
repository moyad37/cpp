#ifndef AAnimal_HPP
#define AAnimal_HPP


#include <string>
#include <iostream>
#include "Brain.hpp"

class AAnimal
{	
	public:
		AAnimal();
		AAnimal(const AAnimal& copy);
		AAnimal& operator=(const AAnimal& copy);
		
		std::string const& getType(void) const;
		virtual void makeSound() const;
		virtual ~AAnimal();

	protected:
		std::string type;
		
};

#endif
