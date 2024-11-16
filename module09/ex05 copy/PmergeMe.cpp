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































// #include "PmergeMe.hpp"
// #include <ctime> // Include for C-style timing

// int parseInput(char **argv) {
//     for (int i = 1; argv[i] != NULL; ++i) {
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
//     for (int i = 1; argv[i] != NULL; ++i) {
//         std::cout << argv[i] << " ";
//     }
//     std::cout << std::endl;
// }

// void displayResult(const std::vector<int>& container, const std::string& type, long time) {
//     std::cout << "After (" << type << "): ";
//     for (size_t i = 0; i < container.size(); ++i) {
//         std::cout << container[i] << " ";
//     }
//     std::cout << "\nTime to process a range of " << container.size() << " elements with " << type << ": "
//               << time << " us" << std::endl;
// }

// void displayResult(const std::deque<int>& container, const std::string& type, long time) {
//     std::cout << "After (" << type << "): ";
//     for (size_t i = 0; i < container.size(); ++i) {
//         std::cout << container[i] << " ";
//     }
//     std::cout << "\nTime to process a range of " << container.size() << " elements with " << type << ": "
//               << time << " us" << std::endl;
// }

// // Ford-Johnson sorting algorithm implementation for vector
// void fordJohnsonSortVector(std::vector<int> &vec) {
//     int n = vec.size();
//     if (n < 2) return;

//     // Base case: Use insertion sort for small sizes
//     if (n <= 10) {
//         std::sort(vec.begin(), vec.end()); // You can replace this with a custom insertion sort
//         return;
//     }

//     // Divide the array into two halves
//     std::vector<int> left(vec.begin(), vec.begin() + n / 2);
//     std::vector<int> right(vec.begin() + n / 2, vec.end());

//     // Recursively sort the two halves
//     fordJohnsonSortVector(left);
//     fordJohnsonSortVector(right);

//     // Merge the two sorted halves
//     std::merge(left.begin(), left.end(), right.begin(), right.end(), vec.begin());
// }

// // Ford-Johnson sorting algorithm implementation for deque
// void fordJohnsonSortDeque(std::deque<int> &deq) {
//     int n = deq.size();
//     if (n < 2) return;

//     // Base case: Use insertion sort for small sizes
//     if (n <= 10) {
//         std::vector<int> temp(deq.begin(), deq.end());
//         std::sort(temp.begin(), temp.end());
//         std::copy(temp.begin(), temp.end(), deq.begin());
//         return;
//     }

//     // Divide the deque into two halves
//     std::deque<int> left(deq.begin(), deq.begin() + n / 2);
//     std::deque<int> right(deq.begin() + n / 2, deq.end());

//     // Recursively sort the two halves
//     fordJohnsonSortDeque(left);
//     fordJohnsonSortDeque(right);

//     // Merge the two sorted halves
//     std::merge(left.begin(), left.end(), right.begin(), right.end(), deq.begin());
// }

// int processVector(char **argv) {
//     std::vector<int> container;
//     for (int i = 1; argv[i] != NULL; ++i) {
//         container.push_back(std::strtol(argv[i], NULL, 10));
//     }

//     // Measure time
//     clock_t start = clock();
//     // Call the Ford-Johnson sort
//     fordJohnsonSortVector(container);
//     clock_t end = clock();

//     // Calculate elapsed time in microseconds (approximation)
//     long duration = (end - start) * 1000000 / CLOCKS_PER_SEC; // convert seconds to microseconds
    
//     displayResult(container, "std::vector", duration);
//     return 0;
// }

// int processDeque(char **argv) {
//     std::deque<int> container;
//     for (int i = 1; argv[i] != NULL; ++i) {
//         container.push_back(std::strtol(argv[i], NULL, 10));
//     }

//     // Measure time
//     clock_t start = clock();
//     fordJohnsonSortDeque(container);
//     clock_t end = clock();

//     // Calculate elapsed time in microseconds (approximation)
//     long duration = (end - start) * 1000000 / CLOCKS_PER_SEC; // convert seconds to microseconds
    
//     displayResult(container, "std::deque", duration);
//     return 0;
// }


#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <limits>  // Für std::numeric_limits

// Parse input arguments
int parseInput(char** argv) {
    for (int i = 1; argv[i] != NULL; ++i) {
        char* end;
        long value = std::strtol(argv[i], &end, 10);
        if (*end != '\0' || value < 0 || value > std::numeric_limits<int>::max()) {
            std::cerr << "Error: \"" << argv[i] << "\" is not a valid positive integer." << std::endl;
            return 1;
        }
    }
    return 0;
}

// Display arguments before processing
void displayArguments(char** argv) {
    std::cout << "Before: ";
    for (int i = 1; argv[i] != NULL; ++i) {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
}

// Display sorting results for std::vector
void displayResult(const std::vector<int>& container, const std::string& type, long time) {
    std::cout << "After (" << type << "): ";
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << "\nTime to process a range of " << container.size() << " elements with " << type << ": "
              << time << " us" << std::endl;
}

// Display sorting results for std::deque
void displayResult(const std::deque<int>& container, const std::string& type, long time) {
    std::cout << "After (" << type << "): ";
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << "\nTime to process a range of " << container.size() << " elements with " << type << ": "
              << time << " us" << std::endl;
}

// Generate Jacobsthal numbers until they exceed n
std::vector<int> generateJacobsthalNumbers(int n) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);  // J(0) = 0
    jacobsthal.push_back(1);  // J(1) = 1
    while (jacobsthal.back() < n) {
        jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);
    }
    return jacobsthal;
}

// Merge-Insertion-Sort using Jacobsthal numbers for accessing indices
void mergeInsertionSortWithJacobsthal(std::vector<int>& vec, int left, int right) {
    int n = right - left + 1;

    if (n <= 10) {
        for (int i = left + 1; i <= right; i++) {
            int key = vec[i];
            int j = i - 1;
            while (j >= left && vec[j] > key) {
                vec[j + 1] = vec[j];
                j--;
            }
            vec[j + 1] = key;
        }
        return;
    }

    int mid = left + (right - left) / 2;

    mergeInsertionSortWithJacobsthal(vec, left, mid);
    mergeInsertionSortWithJacobsthal(vec, mid + 1, right);

    std::vector<int> jacobsthal = generateJacobsthalNumbers(right);

    size_t jacobsthalIndex = 0;
    std::vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (jacobsthalIndex < jacobsthal.size()) {
            int jumpIndex = jacobsthal[jacobsthalIndex];
            if (jumpIndex < right) {
                if (vec[i] <= vec[j]) {
                    temp.push_back(vec[i]);
                    i++;
                } else {
                    temp.push_back(vec[j]);
                    j++;
                }
                jacobsthalIndex++;
            } else {
                break;
            }
        }
    }

    while (i <= mid) {
        temp.push_back(vec[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(vec[j]);
        j++;
    }

    for (size_t k = 0; k < temp.size(); k++) {
        vec[left + k] = temp[k];
    }
}

// Ford-Johnson sorting with Jacobsthal number based merge for vectors
void fordJohnsonSortVectorWithJacobsthal(std::vector<int>& vec) {
    mergeInsertionSortWithJacobsthal(vec, 0, vec.size() - 1);
}

// Process vector using Jacobsthal-based Ford-Johnson sort
int processVector(char** argv) {
    std::vector<int> container;
    for (int i = 1; argv[i] != NULL; ++i) {
        container.push_back(std::strtol(argv[i], NULL, 10));
    }

    clock_t start = clock();  // Start time measurement
    fordJohnsonSortVectorWithJacobsthal(container);  // Sort the vector
    clock_t end = clock();  // End time measurement

    long duration = (end - start) * 1000000 / CLOCKS_PER_SEC;  // Convert clock ticks to microseconds
    displayResult(container, "std::vector with Jacobsthal", duration);  // Display results

    return 0;
}

// Process deque with Jacobsthal numbers
int processDeque(char** argv) {
    std::deque<int> container;
    for (int i = 1; argv[i] != NULL; ++i) {
        container.push_back(std::strtol(argv[i], NULL, 10));
    }

    clock_t start = clock();  // Start time measurement
    std::vector<int> vec(container.begin(), container.end());  // Convert deque to vector
    fordJohnsonSortVectorWithJacobsthal(vec);  // Sort the vector
    clock_t end = clock();  // End time measurement

    long duration = (end - start) * 1000000 / CLOCKS_PER_SEC;  // Convert clock ticks to microseconds
    displayResult(vec, "std::deque with Jacobsthal", duration);  // Display results

    return 0;
}
