#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

// Merge-Insertion sort function for vector
void PmergeMe::mergeInsertSort(std::vector<int>& container)
{
    // Placeholder: for now, using std::sort as merge-insert sort implementation.
    std::sort(container.begin(), container.end());
}

// Merge-Insertion sort function for deque
void PmergeMe::mergeInsertSort(std::deque<int>& container)
{
    // Placeholder: for now, using std::sort as merge-insert sort implementation.
    std::sort(container.begin(), container.end());
}

// Function to display the time used by each container
void PmergeMe::displayResults(const std::string& containerName, double timeUsed)
{
    std::cout << "Time to process with " << containerName << ": " << timeUsed << " seconds" << std::endl;
}
