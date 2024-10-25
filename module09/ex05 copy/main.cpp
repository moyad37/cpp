#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Not enough arguments." << std::endl;
        return 1;
    }

    if (parseInput(argv) != 0) return 1;

    displayArguments(argv);

    clock_t startTime = clock();
    if (processVector(argv, startTime) != 0) return 1;
    startTime = clock() - startTime;

    if (processDeque(argv, startTime) != 0) return 1;

    return 0;
}
