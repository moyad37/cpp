// #include "BitcoinExchange.hpp"

// int main(int argc, char** argv) {
//     if (argc != 2) {
//         std::cerr << "Error: please provide a file as argument." << std::endl;
//         return 1;
//     }

//     BitcoinExchange btc("data.csv");
//     btc.processInputFile(argv[1]);

//     return 0;
// }


#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange btc("data.csv");
    btc.processInput(argv[1]);

    return 0;
}
