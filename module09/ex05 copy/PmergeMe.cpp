// #include "PmergeMe.hpp"

// int parseInput(char **argv) {
//     for (int i = 1; argv[i] != NULL; ++i) {  // Change nullptr to NULL
//         char *end;
//         long value = std::strtol(argv[i], &end, 10);
//         if (*end != '\0' || value < 0 || value > std::numeric_limits<int>::max()) {
//             std::cerr << "Error: \"" << argv[i] << "\" is not a valid positive integer." << std::endl;
//             return 1;
//         }
//     }
//     return 0;
// }

// void displayArguments(char **argv) {
//     std::cout << "Before: ";
//     for (int i = 1; argv[i] != NULL; ++i) {  // Change nullptr to NULL
//         std::cout << argv[i] << " ";
//     }
//     std::cout << std::endl;
// }

// int processVector(char **argv, clock_t &time) {
//     std::vector<int> container;
//     for (int i = 1; argv[i] != NULL; ++i) {  // Change nullptr to NULL
//         container.push_back(std::strtol(argv[i], NULL, 10));  // Change nullptr to NULL
//     }
//     std::sort(container.begin(), container.end());

//     time = clock() - time;
//     displayResult(container, "std::vector", time);
//     return 0;
// }

// int processDeque(char **argv, clock_t &time) {
//     std::deque<int> container;
//     for (int i = 1; argv[i] != NULL; ++i) {  // Change nullptr to NULL
//         container.push_back(std::strtol(argv[i], NULL, 10));  // Change nullptr to NULL
//     }
//     std::sort(container.begin(), container.end());

//     time = clock() - time;
//     displayResult(container, "std::deque", time);
//     return 0;
// }

// void displayResult(const std::vector<int> &container, const std::string &type, clock_t time) {
//     std::cout << "After (" << type << "): ";
//     for (size_t i = 0; i < container.size(); ++i) {
//         std::cout << container[i] << " ";
//     }
//     std::cout << "\nTime with \"" << type << "\": " << static_cast<float>(time) / CLOCKS_PER_SEC << " seconds." << std::endl;
// }

// void displayResult(const std::deque<int> &container, const std::string &type, clock_t time) {
//     std::cout << "After (" << type << "): ";
//     for (size_t i = 0; i < container.size(); ++i) {
//         std::cout << container[i] << " ";
//     }
//     std::cout << "\nTime with \"" << type << "\": " << static_cast<float>(time) / CLOCKS_PER_SEC << " seconds." << std::endl;
// }



#include "PmergeMe.hpp"
#include <ctime> // Include for C-style timing

int parseInput(char **argv) {
    for (int i = 1; argv[i] != NULL; ++i) {
        char *end;
        long value = std::strtol(argv[i], &end, 10);
        if (*end != '\0' || value < 0 || value > std::numeric_limits<int>::max()) {
            std::cerr << "Error: \"" << argv[i] << "\" is not a valid positive integer." << std::endl;
            return 1;
        }
    }
    return 0;
}

void displayArguments(char **argv) {
    std::cout << "Before: ";
    for (int i = 1; argv[i] != NULL; ++i) {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
}

void displayResult(const std::vector<int>& container, const std::string& type, long time) {
    std::cout << "After (" << type << "): ";
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << "\nTime to process a range of " << container.size() << " elements with " << type << ": "
              << time << " us" << std::endl;
}

void displayResult(const std::deque<int>& container, const std::string& type, long time) {
    std::cout << "After (" << type << "): ";
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << "\nTime to process a range of " << container.size() << " elements with " << type << ": "
              << time << " us" << std::endl;
}

// Ford-Johnson sorting algorithm implementation for vector
void fordJohnsonSortVector(std::vector<int> &vec) {
    int n = vec.size();
    if (n < 2) return;

    // Base case: Use insertion sort for small sizes
    if (n <= 10) {
        std::sort(vec.begin(), vec.end()); // You can replace this with a custom insertion sort
        return;
    }

    // Divide the array into two halves
    std::vector<int> left(vec.begin(), vec.begin() + n / 2);
    std::vector<int> right(vec.begin() + n / 2, vec.end());

    // Recursively sort the two halves
    fordJohnsonSortVector(left);
    fordJohnsonSortVector(right);

    // Merge the two sorted halves
    std::merge(left.begin(), left.end(), right.begin(), right.end(), vec.begin());
}

// Ford-Johnson sorting algorithm implementation for deque
void fordJohnsonSortDeque(std::deque<int> &deq) {
    int n = deq.size();
    if (n < 2) return;

    // Base case: Use insertion sort for small sizes
    if (n <= 10) {
        std::vector<int> temp(deq.begin(), deq.end());
        std::sort(temp.begin(), temp.end());
        std::copy(temp.begin(), temp.end(), deq.begin());
        return;
    }

    // Divide the deque into two halves
    std::deque<int> left(deq.begin(), deq.begin() + n / 2);
    std::deque<int> right(deq.begin() + n / 2, deq.end());

    // Recursively sort the two halves
    fordJohnsonSortDeque(left);
    fordJohnsonSortDeque(right);

    // Merge the two sorted halves
    std::merge(left.begin(), left.end(), right.begin(), right.end(), deq.begin());
}

int processVector(char **argv) {
    std::vector<int> container;
    for (int i = 1; argv[i] != NULL; ++i) {
        container.push_back(std::strtol(argv[i], NULL, 10));
    }

    // Measure time
    clock_t start = clock();
    // Call the Ford-Johnson sort
    fordJohnsonSortVector(container);
    clock_t end = clock();

    // Calculate elapsed time in microseconds (approximation)
    long duration = (end - start) * 1000000 / CLOCKS_PER_SEC; // convert seconds to microseconds
    
    displayResult(container, "std::vector", duration);
    return 0;
}

int processDeque(char **argv) {
    std::deque<int> container;
    for (int i = 1; argv[i] != NULL; ++i) {
        container.push_back(std::strtol(argv[i], NULL, 10));
    }

    // Measure time
    clock_t start = clock();
    fordJohnsonSortDeque(container);
    clock_t end = clock();

    // Calculate elapsed time in microseconds (approximation)
    long duration = (end - start) * 1000000 / CLOCKS_PER_SEC; // convert seconds to microseconds
    
    displayResult(container, "std::deque", duration);
    return 0;
}
