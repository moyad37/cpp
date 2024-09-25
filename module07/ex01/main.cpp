/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:06:06 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/25 13:54:59 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(const T& elem) {
    std::cout << elem << " ";
}

int main() {

    int intArray[] = {1, 2, 3, 4, 5, 3, 6, 5, 3, 2};
    std::cout << "intArray: ";
    iter(intArray, 10, printElement);
    std::cout << std::endl;


    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    std::cout << "floatArray: ";
    iter(floatArray, 5, printElement<float>);
    std::cout << std::endl;

    std::string stringArray[] = {"Hello", "World", "C++", "Templates"};
    std::cout << "stringArray: ";
    iter(stringArray, 4, printElement<std::string>);
    std::cout << std::endl;
    return 0;
}





