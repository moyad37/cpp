/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:55:01 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/25 22:07:32 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
    // Test with std::vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test with std::list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);
    
    try {
        std::list<int>::iterator it = easyfind(lst, 40);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test for an element not found in the container
    try {
        std::vector<int>::iterator it = easyfind(vec, 232);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}




// #include "easyfind.hpp"
// #include <iostream>
// #include <vector>

// int main( void ) {
// 	std::vector<int> v;
// 	std::vector<int>::iterator it;

// 	v.push_back(1);
// 	v.push_back(2);
// 	v.push_back(3);
// 	v.push_back(4);
// 	v.push_back(5);

// 	it = easyfind(v, 3);
// 	if (it != v.end())
// 		std::cout << "Found: " << *it << std::endl;
// 	else
// 		std::cout << "Not found" << std::endl;

// 	it = easyfind(v, 42);
// 	if (it != v.end())
// 		std::cout << "Found: " << *it << std::endl;
// 	else
// 		std::cout << "Not found" << std::endl;

// 	return 0;
// }