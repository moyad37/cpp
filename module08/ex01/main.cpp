/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:55:34 by mmanssou          #+#    #+#             */
/*   Updated: 2024/10/09 17:59:09 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Span.hpp"
#include <iostream>
#include <vector>
#include <ctime> 
int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;


        std::vector<int> moreNumbers;
        moreNumbers.push_back(12);
        moreNumbers.push_back(24);
        moreNumbers.push_back(36);

        Span bigSpan(10);
        bigSpan.addNumbers(moreNumbers.begin(), moreNumbers.end());
        
        bigSpan.addNumber(42);
        bigSpan.addNumber(55);
        bigSpan.addNumber(67);
        bigSpan.addNumber(89);
        
        std::cout << "second Span Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "second Span Longest: " << bigSpan.longestSpan() << std::endl;
        
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    // Test mit 10.000 zufälligen Zahlen
    try{

    const unsigned int NUM_COUNT = 10000;
    Span bigSpan(NUM_COUNT);
    
    std::vector<int> randomNumbers;
    std::srand(static_cast<unsigned int>(std::time(0))); 

    for (unsigned int i = 0; i < (NUM_COUNT); ++i) {
        randomNumbers.push_back(std::rand() % 100000);
    }

    bigSpan.addNumbers(randomNumbers.begin(), randomNumbers.end());


    std::cout << "Big Span Shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Big Span Longest: " << bigSpan.longestSpan() << std::endl;
        
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
