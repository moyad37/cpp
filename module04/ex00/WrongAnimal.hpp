
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal& operator=(const WrongAnimal& copy);

		void		makeSound() const;
		std::string const& getType() const;
		~WrongAnimal();

	protected:
		std::string	type;
};

#endif
