/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:06:06 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/09 20:08:49 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

// Eine einfache Funktion, die ein Element druckt
template <typename T>
void printElement(const T& elem) {
    std::cout << elem << " ";
}

int main() {
    // Test 1: Array von int-Werten
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "intArray: ";
    // explizite Instanziierung für int
    iter<int, void(*)(const int&)>(intArray, 5, printElement<int>);
    std::cout << std::endl;

    // Test 2: Array von float-Werten
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    std::cout << "floatArray: ";
    // explizite Instanziierung für float
    iter<float, void(*)(const float&)>(floatArray, 5, printElement<float>);
    std::cout << std::endl;

    // Test 3: Array von std::string
    std::string stringArray[] = {"Hello", "World", "C++", "Templates"};
    std::cout << "stringArray: ";
    // explizite Instanziierung für std::string
    iter<std::string, void(*)(const std::string&)>(stringArray, 4, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}

