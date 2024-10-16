/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:19:36 by mmanssou          #+#    #+#             */
/*   Updated: 2024/10/03 16:41:02 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cstddef>

template <typename T>
class Array {
private:
    T* data;            
    std::size_t length; 

public:

    Array() : data(NULL), length(0) {}


    explicit Array(unsigned int n) : data(new T[n]()), length(n) {}

    Array(const Array& other) : data(NULL), length(0) {
        *this = other;
    }

    ~Array() {
        delete[] data;
    }

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
    

    class OutOfBoundsException : public std::exception {
    public:

        const char* what() const throw() {
            return "Index out of bounds";
        }
    };

    T& operator[](std::size_t index) {
        if (index >= length || index < 0) {
            throw OutOfBoundsException();  
        }
        return data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= length || index < 0) {
            throw OutOfBoundsException();
        }
        return data[index];
    }

    std::size_t size() const {
        return length;
    }
};


#endif






