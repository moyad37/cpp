#include "PmergeMe.hpp"
#include <ctime>  // for clock_t, clock(), CLOCKS_PER_SEC

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe <positive integers>" << std::endl;
        return 1;
    }

    PmergeMe sorter;

    // Containers to hold the input sequence
    std::vector<int> vec;
    std::deque<int> deq;

    // Parsing command line arguments and filling the containers
    for (int i = 1; i < argc; ++i)
    {
        int num;
        std::stringstream ss(argv[i]);
        if (!(ss >> num) || num <= 0)  // Ensure input is a positive integer
        {
            std::cerr << "Error: invalid input, only positive integers are allowed." << std::endl;
            return 1;
        }
        vec.push_back(num);
        deq.push_back(num);
    }

    // Display the unsorted input sequence
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << (i < vec.size() - 1 ? " " : "");
    std::cout << std::endl;

    // Measure time for vector sorting
    clock_t start_vec = clock();
    sorter.mergeInsertSort(vec);
    clock_t end_vec = clock();
    double timeUsedVector = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;

    // Measure time for deque sorting
    clock_t start_deq = clock();
    sorter.mergeInsertSort(deq);
    clock_t end_deq = clock();
    double timeUsedDeque = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC;

    // Display the sorted sequence
    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << (i < vec.size() - 1 ? " " : "");
    std::cout << std::endl;

    // Display time results
    sorter.displayResults("std::vector", timeUsedVector);
    sorter.displayResults("std::deque", timeUsedDeque);

    return 0;
}
