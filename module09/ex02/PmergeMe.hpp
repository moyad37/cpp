#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <cstdlib>  // for exit() and atoi()
#include <algorithm> // for std::sort

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    // Sorting functions for vector and deque
    void mergeInsertSort(std::vector<int>& container);
    void mergeInsertSort(std::deque<int>& container);

    // Display timing results
    void displayResults(const std::string& containerName, double timeUsed);
};

#endif
