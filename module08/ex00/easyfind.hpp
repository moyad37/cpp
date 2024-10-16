/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:54:37 by mmanssou          #+#    #+#             */
/*   Updated: 2024/10/09 17:14:22 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception> 
#include <iostream> 


class NotFoundException : public std::exception {
public:
    NotFoundException() {};
    NotFoundException(const NotFoundException& other) {
        (void)other; 
    }
    NotFoundException& operator=(const NotFoundException& other) {
        (void)other;
        return *this;
    }
    ~NotFoundException(void) throw() {};
    const char* what() const throw() {
        return "Element not found in the container!";
    }
};


template <typename T>
typename T::iterator easyfind(T& container, int n) {
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    
    if (it == container.end()) {
        throw NotFoundException(); 
    }
    
    return it;
}

#endif

