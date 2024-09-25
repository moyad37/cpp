#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class Span {
public:
    Span(unsigned int n);
    Span(const Span& other);
    ~Span();

    Span& operator=(const Span& other);

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end) {
        if (std::distance(begin, end) > static_cast<int>(maxSize - numbers.size())) {
            throw std::out_of_range("Span: Not enough space to add all numbers");
        }
        numbers.insert(numbers.end(), begin, end);
    }

private:
    std::vector<int> numbers;
    unsigned int maxSize;
};

#endif
