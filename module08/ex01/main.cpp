#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(1);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(10);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Adding a range of numbers
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
        
        std::cout << "Big Span Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Big Span Longest: " << bigSpan.longestSpan() << std::endl;
        
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
