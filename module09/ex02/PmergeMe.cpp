
#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "PmergeMe.hpp"



int parseInput(char** argv) {
    for (int i = 1; argv[i] != NULL; ++i) {
        char* end;
        long value = std::strtol(argv[i], &end, 10);

        // Überprüfen, ob es eine gültige Zahl ist und ob sie positiv ist
        if (*end != '\0' || value <= 0 || value > std::numeric_limits<int>::max()) {
            std::cerr << "Error: \"" << argv[i] << "\" is not a valid positive integer greater than 0." << std::endl;
            return 1;
        }
    }
    return 0;
}

void displayArguments(char** argv) {
    std::cout << "Before: ";
    for (int i = 1; argv[i] != NULL; ++i) {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
}


void displayResult(const std::deque<int>& container, const std::string& type, long time) {
    std::cout << "After (" << type << "): ";
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << "\nTime to process a range of " << container.size() << " elements with " << type << ": "
              << time << " us" << std::endl;
}


void displayResult(const std::vector<int>& container, const std::string& type, long time) {
    std::cout << "After (" << type << "): ";
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << "\nTime to process a range of " << container.size() << " elements with " << type << ": "
              << time << " us" << std::endl;
}

std::vector<int> generateJacobsthalNumbers(int n) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    while (jacobsthal.back() < n) {
        jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);
    }
    return jacobsthal;
}

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

void mergeInsertionSortWithJacobsthalDeque(std::deque<int>& deque, int left, int right) {
    int n = right - left + 1;

    if (n <= 10) {
        for (int i = left + 1; i <= right; i++) {
            int key = deque[i];
            int j = i - 1;
            while (j >= left && deque[j] > key) {
                deque[j + 1] = deque[j];
                j--;
            }
            deque[j + 1] = key;
        }
        return;
    }

    int mid = left + (right - left) / 2;

    mergeInsertionSortWithJacobsthalDeque(deque, left, mid);
    mergeInsertionSortWithJacobsthalDeque(deque, mid + 1, right);

    std::vector<int> jacobsthal = generateJacobsthalNumbers(right);

    size_t jacobsthalIndex = 0;
    std::deque<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (jacobsthalIndex < jacobsthal.size()) {
            int jumpIndex = jacobsthal[jacobsthalIndex];
            if (jumpIndex < right) {
                if (deque[i] <= deque[j]) {
                    temp.push_back(deque[i]);
                    i++;
                } else {
                    temp.push_back(deque[j]);
                    j++;
                }
                jacobsthalIndex++;
            } else {
                break;
            }
        }
    }

    while (i <= mid) {
        temp.push_back(deque[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(deque[j]);
        j++;
    }

    for (size_t k = 0; k < temp.size(); k++) {
        deque[left + k] = temp[k];
    }
}

void fordJohnsonSortVectorWithJacobsthal(std::vector<int>& vec) {
    mergeInsertionSortWithJacobsthal(vec, 0, vec.size() - 1);
}

void fordJohnsonSortDequeWithJacobsthal(std::deque<int>& deque) {
    mergeInsertionSortWithJacobsthalDeque(deque, 0, deque.size() - 1);
}

int processVector(char** argv) {
    std::vector<int> container;
    for (int i = 1; argv[i] != NULL; ++i) {
        container.push_back(std::strtol(argv[i], NULL, 10));
    }

    clock_t start = clock();
    fordJohnsonSortVectorWithJacobsthal(container);
    clock_t end = clock();

    long duration = (end - start) * 1000000 / CLOCKS_PER_SEC; 
    displayResult(container, "std::vector", duration); 

    return 0;
}

int processDeque(char** argv) {
    std::deque<int> container;
    for (int i = 1; argv[i] != NULL; ++i) {
        container.push_back(std::strtol(argv[i], NULL, 10));
    }
    clock_t start = clock();  
    fordJohnsonSortDequeWithJacobsthal(container); 
    clock_t end = clock(); 

    long duration = (end - start) * 1000000 / CLOCKS_PER_SEC;  
    displayResult(container, "std::deque", duration); 
    return 0;
}
