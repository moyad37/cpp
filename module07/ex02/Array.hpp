/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:19:36 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/13 18:01:44 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <iostream>
#include <stdexcept> // Für std::out_of_range
#include <cstddef>   // Für std::size_t

template <typename T>
class Array {
private:
    T* data;            // Pointer für die Array-Elemente
    std::size_t length; // Größe des Arrays

public:
    // Standardkonstruktor: Erstellt ein leeres Array
    Array() : data(NULL), length(0) {}

    // Konstruktor mit einem Parameter für die Array-Größe
    explicit Array(unsigned int n) : data(new T[n]()), length(n) {}

    // Kopierkonstruktor
    Array(const Array& other) : data(NULL), length(0) {
        *this = other;
    }

    // Destruktor: Freigeben des Speichers
    ~Array() {
        delete[] data;
    }

    // Zuweisungsoperator
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new T[length];
            for (std::size_t i = 0; i < length; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Subskriptoperator: Zugriff auf das Array-Element
    T& operator[](std::size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // Konstanter Subskriptoperator: Zugriff auf das Array-Element (für konstante Instanzen)
    const T& operator[](std::size_t index) const {
        if (index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // Funktion zur Rückgabe der Array-Größe
    std::size_t size() const {
        return length;
    }
};

// Ausgabeoperator für das Array (optional, um das Array leicht auszugeben)
template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr) {
    os << "[";
    for (std::size_t i = 0; i < arr.size(); ++i) {
        os << arr[i];
        if (i < arr.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}













// #pragma once
// #include <iostream>

// #define DEFAULT "\033[0m"
// #define BLACK "\033[30m"
// #define GREY "\033[90m"
// #define RED "\033[31m"
// #define CYAN "\033[36m"
// #define GREEN "\033[32m"
// #define YELLOW "\033[33m"
// #define BLUE "\033[94m"
// #define MAGENTA "\033[35m"

// //Template class Array !!!
// template <typename T>
// class Array
// {
// private:
// 	T *_array;
// 	size_t _size;
// public:
// 	//Default constructor
// 	Array() : _array(NULL), _size(0) { std::cout << GREEN << "Default constructor called" << DEFAULT << std::endl;};

// 	//Destructor
// 	~Array() { delete[] _array; std::cout << RED << "Destructor called" << DEFAULT << std::endl; };

// 	//Parameter constructor
// 	Array(unsigned int n) : _array(new T[n]()), _size(n) { std::cout << CYAN << "Parameterized constructor called" << DEFAULT << std::endl; };

// 	//Copy constructor
// 	Array(const Array &other) : _array(new T[other._size]()), _size(other._size)
// 	{
// 		std::cout << BLUE << "Copy constructor called" << DEFAULT << std::endl;
// 		for (size_t i = 0; i < _size; i++)
// 			_array[i] = other._array[i];
// 	};

// 	//Assignment operator
// 	Array &operator=(const Array &copy)
// 	{
// 		std::cout << YELLOW << "Assignment operator called" << DEFAULT << std::endl;
// 		if (this == &copy)
// 			return *this;
// 		delete[] _array;
// 		_array = new T[copy._size]();
// 		_size = copy._size;
// 		for (size_t i = 0; i < _size; i++)
// 			_array[i] = copy._array[i];
// 		return *this;
// 	};

// 	//check if the index is out of range
// 	T &operator[](unsigned int i)
// 	{
// 		if (i >= _size)
// 			throw std::out_of_range("Sorry. The index is out of the range");
// 		return _array[i];
// 	};

// 	//returns the size of the array
// 	size_t size() const { return _size; };

// 	//Exception class
// 	class OutOfRange : public std::exception
// 	{
// 		virtual const char *what() const throw()
// 		{
// 			return "Sorry. The index is outside of the range";
// 		};
// 	};

// };













// # include <iostream>

// template<typename T>
// class	Array
// {
// 	public:
// 			Array();
// 			Array(unsigned int	size);
// 			Array(const Array& other);
// 			Array&	operator=(const Array& other);
// 			T&		operator[](unsigned int index);
// 			~Array();

// 			unsigned int	size();

// 			class	InvalidIndexException : public std::exception
// 			{
// 				public:
// 						virtual const char *what() const throw();
// 			};

// 	private:
// 			T				*array_;
// 			unsigned int	size_;
// };

// # include "Array.tpp"


#endif


