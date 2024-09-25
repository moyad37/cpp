#include "Span.hpp"
#include <algorithm>  // For std::sort, std::min_element, std::max_element
#include <limits>     // For std::numeric_limits

// Constructor to initialize maxSize with the passed value N
Span::Span(unsigned int N) : numbers(), maxSize(N) {}

// Copy constructor to copy values from another Span object
Span::Span(const Span &other) : numbers(other.numbers), maxSize(other.maxSize) {}

// Destructor (empty because there's no dynamic memory to clean up)
Span::~Span() {}

// Assignment operator to copy values from another Span object
Span& Span::operator=(const Span &other) {
    if (this != &other) {
        this->maxSize = other.maxSize;
        this->numbers = other.numbers;
    }
    return *this;
}

// Function to add a number to the Span
void Span::addNumber(int number) {
    if (numbers.size() >= maxSize) {
        throw std::out_of_range("Span is full. Cannot add more numbers.");
    }
    numbers.push_back(number);
}

// Function to find the shortest span (minimum difference)
int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span.");
    }
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    
    int minSpan = std::numeric_limits<int>::max();  // Requires #include <limits>
    for (std::size_t i = 1; i < sortedNumbers.size(); ++i) {
        minSpan = std::min(minSpan, sortedNumbers[i] - sortedNumbers[i - 1]);
    }
    return minSpan;
}

// Function to find the longest span (maximum difference)
int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span.");
    }
    int minElement = *std::min_element(numbers.begin(), numbers.end());
    int maxElement = *std::max_element(numbers.begin(), numbers.end());
    return maxElement - minElement;
}
