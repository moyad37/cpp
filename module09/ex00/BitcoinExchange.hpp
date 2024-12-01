
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

class BitcoinExchange {
public:

    BitcoinExchange();                              
    BitcoinExchange(const std::string& dbFile);       
    BitcoinExchange(const BitcoinExchange& other);    
    BitcoinExchange& operator=(const BitcoinExchange& other); 
    ~BitcoinExchange();                                
    BitcoinExchange(BitcoinExchange&& other) noexcept;
    BitcoinExchange& operator=(BitcoinExchange&& other) noexcept;

    bool processInput(const std::string& inputFile);
    
private:
    std::map<std::string, float> _data;

    bool parseDatabase(const std::string& dbFile);
    bool isValidDate(const std::string& date);
    bool isLeapYear(int year);
    std::string findClosestDate(const std::string& date);
};

#endif
