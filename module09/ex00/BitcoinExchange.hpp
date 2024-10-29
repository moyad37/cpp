// #ifndef BITCOINEXCHANGE_HPP
// #define BITCOINEXCHANGE_HPP

// #include <iostream>
// #include <map>
// #include <string>

// class BitcoinExchange {
// public:
//     BitcoinExchange(const std::string &datafile);
//     float getExchangeRate(const std::string &date) const;
//     void processInputFile(const std::string &inputfile) const;

// private:
//     std::map<std::string, float> exchangeRates;

//     bool isValidDate(const std::string &date) const;
//     bool isValidValue(const std::string &value) const;
//     bool parseCSV(const std::string &filepath);
// };

// #endif

























// #ifndef BITCOINEXCHANGE_HPP
// #define BITCOINEXCHANGE_HPP

// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <map>
// #include <string>

// class BitcoinExchange {
// public:
//     BitcoinExchange(const std::string& dbFile);
//     ~BitcoinExchange();

//     bool processInput(const std::string& inputFile);
    
// private:
//     std::map<std::string, float> _data;

//     bool parseDatabase(const std::string& dbFile);
//     bool isValidDate(const std::string& date);
//     bool isLeapYear(int year);
//     std::string findClosestDate(const std::string& date);
// };

// #endif

























#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

class BitcoinExchange {
public:
    // Orthodox Canonical Form
    BitcoinExchange();                                 // Default constructor
    BitcoinExchange(const std::string& dbFile);        // Parameterized constructor
    BitcoinExchange(const BitcoinExchange& other);     // Copy constructor
    BitcoinExchange& operator=(const BitcoinExchange& other); // Copy assignment operator
    ~BitcoinExchange();                                // Destructor
    BitcoinExchange(BitcoinExchange&& other) noexcept; // Move constructor
    BitcoinExchange& operator=(BitcoinExchange&& other) noexcept; // Move assignment operator

    bool processInput(const std::string& inputFile);
    
private:
    std::map<std::string, float> _data;

    bool parseDatabase(const std::string& dbFile);
    bool isValidDate(const std::string& date);
    bool isLeapYear(int year);
    std::string findClosestDate(const std::string& date);
};

#endif
