/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:55:28 by mmanssou          #+#    #+#             */
/*   Updated: 2024/10/09 17:55:30 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>  
#include <limits>    

Span::Span(unsigned int N) : numbers(), maxSize(N) {}

Span::Span(const Span &other) : numbers(other.numbers), maxSize(other.maxSize) {}


Span::~Span() {}


Span& Span::operator=(const Span &other) {
    if (this != &other) {
        this->maxSize = other.maxSize;
        this->numbers = other.numbers;
    }
    return *this;
}


void Span::addNumber(int number) {
    if (numbers.size() >= maxSize) {
        throw std::out_of_range("Span is full. Cannot add more numbers.");
    }
    numbers.push_back(number);
}


int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span.");
    }
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    
    int minSpan = std::numeric_limits<int>::max();
    for (std::size_t i = 1; i < sortedNumbers.size(); ++i) {
        minSpan = std::min(minSpan, sortedNumbers[i] - sortedNumbers[i - 1]);
    }
    return minSpan;
}


int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span.");
    }
    int minElement = *std::min_element(numbers.begin(), numbers.end());
    int maxElement = *std::max_element(numbers.begin(), numbers.end());
    return maxElement - minElement;
}
