#include <iostream>
#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl; // Output: 17
    mstack.pop();
    std::cout << mstack.size() << std::endl; // Output: 1
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Using iterators to print the contents of the stack
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it; // Move iterator forward
    --it; // Move iterator backward

    while (it != ite) {
        std::cout << *it << std::endl; // Output the elements
        ++it; // Increment the iterator
    }

    std::stack<int> s(mstack); // Copying MutantStack to std::stack
    return 0;
}
