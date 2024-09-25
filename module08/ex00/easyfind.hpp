/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:54:37 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/25 22:07:41 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // For std::find
#include <exception> // For exception handling
#include <iostream>  // For standard output

// Custom exception class to handle not found case
class NotFoundException : public std::exception {
public:
    const char* what() const throw() {
        return "Element not found in the container!";
    }
};

// Function template to search for an integer in the container
template <typename T>
typename T::iterator easyfind(T& container, int n) {
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    
    if (it == container.end()) {
        throw NotFoundException(); // Throw exception if not found
    }
    
    return it; // Return iterator to the found element
}

#endif

