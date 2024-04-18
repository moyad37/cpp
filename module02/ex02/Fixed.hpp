
#include <iostream>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int					num;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int integer);
		Fixed(const float floatNumber);
		Fixed( const Fixed& Copy );
		Fixed& operator = (const Fixed &src);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		bool operator< (const Fixed &src);
		bool operator> (const Fixed &src);
		bool operator<= (const Fixed &src);
		bool operator>= (const Fixed &src);
		bool operator== (const Fixed &src);
		bool operator!= (const Fixed &src);
	
		Fixed operator+ (const Fixed &src);
		Fixed operator- (const Fixed &src);
		Fixed operator/ (const Fixed &src);
		Fixed operator* (const Fixed &src);
	
		Fixed operator++(int); // ++ after
		Fixed& operator++(); // ++ bevor
		Fixed operator--(int);
		Fixed& operator--();

		static Fixed& min(Fixed& fp1, Fixed& fp2);
		static const Fixed& min(const Fixed& fp1, const Fixed& fp2);
		static Fixed& max(Fixed& fp1, Fixed& fp2);
		static const Fixed& max(const Fixed& fp1, const Fixed& fp2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
