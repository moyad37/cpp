#include "PmergeMe.hpp"

bool areInputsSorted(char** argv) {
    for (int i = 1; argv[i + 1] != NULL; ++i) {
        int current = std::strtol(argv[i], NULL, 10);
        int next = std::strtol(argv[i + 1], NULL, 10);

        // Überprüfen, ob die Zahlen gültige positive Zahlen sind
        if (current <= 0 || next <= 0) {
            std::cerr << "Error: \"" << argv[i] << "\" or \"" << argv[i + 1] << "\" is not a valid positive integer greater than 0." << std::endl;
            return false;
        }

        // Überprüfen, ob die Zahlen sortiert sind
        if (current > next) {
            return false;
        }
    }
    return true;
}
int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Not enough arguments." << std::endl;
        return 1;
    }

    if (argc == 2) {
        std::cerr << "Error: only one argument provided." << std::endl;
        return 1;
    }

    // Prüfen, ob alle Eingabewerte gültige positive Zahlen sind
    if (parseInput(argv) != 0) return 1;

    // Überprüfen, ob die Eingaben sortiert sind
    if (areInputsSorted(argv)) {
        std::cout << "Is Sorted." << std::endl;
        return 0;
    }

    displayArguments(argv);

    // Verarbeitung mit Vector
    if (processVector(argv) != 0) return 1;

    // Verarbeitung mit Deque
    if (processDeque(argv) != 0) return 1;

    return 0;
}
