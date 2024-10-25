#include "PmergeMe.hpp"

int parseInput(char **argv) {
    for (int i = 1; argv[i] != NULL; ++i) {  // Change nullptr to NULL
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
    for (int i = 1; argv[i] != NULL; ++i) {  // Change nullptr to NULL
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
}

int processVector(char **argv, clock_t &time) {
    std::vector<int> container;
    for (int i = 1; argv[i] != NULL; ++i) {  // Change nullptr to NULL
        container.push_back(std::strtol(argv[i], NULL, 10));  // Change nullptr to NULL
    }
    std::sort(container.begin(), container.end());

    time = clock() - time;
    displayResult(container, "std::vector", time);
    return 0;
}

int processDeque(char **argv, clock_t &time) {
    std::deque<int> container;
    for (int i = 1; argv[i] != NULL; ++i) {  // Change nullptr to NULL
        container.push_back(std::strtol(argv[i], NULL, 10));  // Change nullptr to NULL
    }
    std::sort(container.begin(), container.end());

    time = clock() - time;
    displayResult(container, "std::deque", time);
    return 0;
}

void displayResult(const std::vector<int> &container, const std::string &type, clock_t time) {
    std::cout << "After (" << type << "): ";
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << "\nTime with \"" << type << "\": " << static_cast<float>(time) / CLOCKS_PER_SEC << " seconds." << std::endl;
}

void displayResult(const std::deque<int> &container, const std::string &type, clock_t time) {
    std::cout << "After (" << type << "): ";
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << "\nTime with \"" << type << "\": " << static_cast<float>(time) / CLOCKS_PER_SEC << " seconds." << std::endl;
}
