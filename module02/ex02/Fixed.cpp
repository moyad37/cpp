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
	return (num >> fractionalBits);
}


//// Operator >, <, >=, <=, == and !=.
bool Fixed::operator< (const Fixed &src) {
	return (num < src.num);
}

bool Fixed::operator> (const Fixed &src) {
	return (num > src.num);
}

bool Fixed::operator<= (const Fixed &src) {
	return (num <= src.num);
}

bool Fixed::operator>= (const Fixed &src) {
	return (num >= src.num);
}

bool Fixed::operator== (const Fixed &src) {
	return (num == src.num);
}

bool Fixed::operator!= (const Fixed &src) {
	return (num != src.num);
}


// operators: +, -, *, and /.

Fixed Fixed::operator+ (const Fixed &src) {
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator- (const Fixed &src) {
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed Fixed::operator/ (const Fixed &src) {
	return Fixed(this->toFloat() / src.toFloat());
}

Fixed Fixed::operator* (const Fixed &src) {
	return Fixed(this->toFloat() * src.toFloat());
}

//   x++ ++x x-- --x

Fixed Fixed::operator++(int) {
	Fixed	tmp;
	
	tmp.setRawBits(num);
	num++;
	return (tmp);
} // Overloading post-increment operator (x++)

Fixed& Fixed::operator++() {
	++num;
	return (*this);

} // Overloading pre-increment operator (++x)

Fixed Fixed::operator--(int) {
	Fixed	tmp;
	
	tmp.setRawBits(num);
	num--;
	return (tmp);
} // Overloading post-decrement operator (x--)

Fixed& Fixed::operator--() {
	--num;
	return (*this);
} // Overloading pre-decrement operator (--x)



Fixed& Fixed::min(Fixed& fp1, Fixed& fp2) {
	return (fp1 <= fp2 ? fp1 : fp2);
}

const Fixed& Fixed::min(const Fixed& fp1, const Fixed& fp2) {
	return (fp1.num <= fp2.num ? fp1 : fp2);
}

Fixed& Fixed::max(Fixed& fp1, Fixed& fp2) {
	return (fp1 >= fp2 ? fp1 : fp2);
}

const Fixed& Fixed::max(const Fixed& fp1, const Fixed& fp2) {
	return (fp1.num >= fp2.num ? fp1 : fp2);
}
