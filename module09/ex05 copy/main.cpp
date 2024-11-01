#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Not enough arguments." << std::endl;
        return 1;
    }

    if (parseInput(argv) != 0) return 1;

    displayArguments(argv);


    if (processVector(argv) != 0) return 1;


    if (processDeque(argv) != 0) return 1;

    return 0;
}
