#include "RPN.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./RPN <expression>" << std::endl;
        return 1;
    }

    RPN rpn;
    if (!rpn.evaluate(argv[1])) {
        return 1;
    }

    return 0;
}
