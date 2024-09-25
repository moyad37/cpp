#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Constructor that forwards to std::stack
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack& other) : std::stack<T>(other) {} // Copy constructor
    MutantStack& operator=(const MutantStack& other) {
        std::stack<T>::operator=(other); // Assignment operator
        return *this;
    }

    // Define the iterator types
    typedef typename std::deque<T>::iterator iterator; // You can also use std::vector if needed
    typedef typename std::deque<T>::const_iterator const_iterator;

    // Begin and end methods for iterators
    iterator begin() {
        return this->c.begin(); // Access the underlying container
    }

    iterator end() {
        return this->c.end();
    }

    const_iterator begin() const {
        return this->c.begin();
    }

    const_iterator end() const {
        return this->c.end();
    }
};

#endif


