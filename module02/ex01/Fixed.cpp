#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->num = 0;
}

Fixed::Fixed ( const Fixed& Copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = Copy;
}

int	Fixed::getRawBits( void ) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->num);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &src)  {
	std::cout << "Copy assignment operator called" << std::endl;
	this->num = src.getRawBits();
	return (*this);
}

void	Fixed::setRawBits( int const raw ) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->num = raw;
}

// output a fixed-point value as a floating-point value
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	return (os << fixed.toFloat());
}

// convert an integer value to a fixed-point representation
Fixed::Fixed(const int integer)
{
    std::cout << "Int constructor called" << std::endl;
	num = integer << fractionalBits;
}

// convert a floating-point number to a fixed-point representation
Fixed::Fixed(const float floatingPoint) {
	std::cout << "Float constructor called" << std::endl;
	num = roundf(floatingPoint * (1 << fractionalBits));
}

// convert a fixed-point value to a floating-point representation
float	Fixed::toFloat( void ) const {
	return ((float)num / (1 << fractionalBits));
}

// convert a fixed-point value to an integer representation
int	Fixed::toInt( void ) const {
	if (num >= 0)
        return (num + (1 << (fractionalBits - 1))) >> fractionalBits;
    else
        return (num - (1 << (fractionalBits - 1))) >> fractionalBits;
}
