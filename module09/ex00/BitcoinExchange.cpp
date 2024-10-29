// #include "BitcoinExchange.hpp"
// #include <fstream>
// #include <sstream>
// #include <iomanip>
// #include <limits>

// // Constructor: load exchange rates from the provided CSV file
// BitcoinExchange::BitcoinExchange(const std::string &datafile) {
//     if (!parseCSV(datafile)) {
//         std::cerr << "Error: could not open or parse data file." << std::endl;
//     }
// }

// // Parse the CSV file and fill the map with exchange rates
// bool BitcoinExchange::parseCSV(const std::string &filepath) {
//     std::ifstream file(filepath);
//     if (!file.is_open()) return false;

//     std::string line, date;
//     float rate;
//     std::getline(file, line); // Skip header line
//     while (std::getline(file, line)) {
//         std::stringstream ss(line);
//         if (std::getline(ss, date, ',') && (ss >> rate)) {
//             exchangeRates[date] = rate;
//         }
//     }
//     file.close();
//     return true;
// }

// // Return the closest exchange rate for a given date
// float BitcoinExchange::getExchangeRate(const std::string &date) const {
//     auto it = exchangeRates.lower_bound(date);

//     // If date is found or there are no smaller dates, return the rate
//     if (it != exchangeRates.end() && it->first == date) {
//         return it->second;
//     }

//     // Otherwise, step back to the previous lower date
//     if (it != exchangeRates.begin()) {
//         --it;
//     }
//     return it->second;
// }

// // Validate date format: YYYY-MM-DD
// bool BitcoinExchange::isValidDate(const std::string &date) const {
//     std::istringstream ss(date);
//     int year, month, day;
//     char delim1, delim2;

//     ss >> year >> delim1 >> month >> delim2 >> day;
//     return ss && (delim1 == '-') && (delim2 == '-') && 
//            (year >= 2009 && year <= 2022) && 
//            (month >= 1 && month <= 12) && 
//            (day >= 1 && day <= 31);
// }

// // Validate value: must be between 0 and 1000
// bool BitcoinExchange::isValidValue(const std::string &value) const {
//     try {
//         float fval = std::stof(value);
//         return fval >= 0 && fval <= 1000;
//     } catch (std::exception &e) {
//         return false;
//     }
// }

// // Process the input file, calculate and print the results
// void BitcoinExchange::processInputFile(const std::string &inputfile) const {
//     std::ifstream file(inputfile);
//     if (!file.is_open()) {
//         std::cerr << "Error: could not open file." << std::endl;
//         return;
//     }

//     std::string line, date, value;
//     std::getline(file, line); // Skip header line
//     while (std::getline(file, line)) {
//         std::stringstream ss(line);
//         if (std::getline(ss, date, '|') && std::getline(ss, value)) {
//             // Remove leading/trailing whitespaces
//             date.erase(0, date.find_first_not_of(" \t"));
//             date.erase(date.find_last_not_of(" \t") + 1);
//             value.erase(0, value.find_first_not_of(" \t"));
//             value.erase(value.find_last_not_of(" \t") + 1);

//             if (!isValidDate(date)) {
//                 std::cerr << "Error: bad input => " << date << std::endl;
//             } else if (!isValidValue(value)) {
//                 std::cerr << "Error: invalid value => " << value << std::endl;
//             } else {
//                 float bitcoinValue = std::stof(value);
//                 float exchangeRate = getExchangeRate(date);
//                 std::cout << date << " => " << bitcoinValue << " = " 
//                           << bitcoinValue * exchangeRate << std::endl;
//             }
//         }
//     }
//     file.close();
// }




































































// #include "BitcoinExchange.hpp"

// // Konstruktor lädt die Datenbank aus der CSV-Datei
// BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
//     if (!parseDatabase(dbFile)) {
//         std::cerr << "Error: could not open or parse data file." << std::endl;
//     }
// }

// // Destruktor
// BitcoinExchange::~BitcoinExchange() {}

// // Liest und analysiert die CSV-Datenbank
// bool BitcoinExchange::parseDatabase(const std::string& dbFile) {
//     std::ifstream file(dbFile);
//     if (!file.is_open()) {
//         return false;
//     }
//     std::string line;
//     std::getline(file, line); // Kopfzeile ignorieren
//     while (std::getline(file, line)) {
//         std::istringstream ss(line);
//         std::string date;
//         std::string rate;
//         if (std::getline(ss, date, ',') && std::getline(ss, rate)) {
//             try {
//                 float exchangeRate = std::stof(rate);
//                 _data[date] = exchangeRate;
//             } catch (const std::exception&) {
//                 std::cerr << "Error: invalid format in data file." << std::endl;
//                 return false;
//             }
//         }
//     }
//     file.close();
//     return true;
// }

// // Überprüft, ob eine Datei existiert und analysiert wird
// bool BitcoinExchange::processInput(const std::string& inputFile) {
//     std::ifstream file(inputFile);
//     if (!file.is_open()) {
//         std::cerr << "Error: could not open file." << std::endl;
//         return false;
//     }
//     std::string line;
//     std::getline(file, line); // Kopfzeile ignorieren
//     while (std::getline(file, line)) {
//         std::istringstream ss(line);
//         std::string date;
//         std::string valueStr;
//         if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
//             date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1); // trim
//             valueStr.erase(0, valueStr.find_first_not_of(" \t\n\r\f\v"));
            
//             try {
//                 float value = std::stof(valueStr);
//                 if (value < 0) {
//                     std::cerr << "Error: not a positive number." << std::endl;
//                 } 
//                 else if (value > 1000) {
//                     std::cerr << "Error: too large a number." << std::endl;
//                 } 
//                 else if (!isValidDate(date)) {
//                     std::cerr << "Error: bad input => " << date << std::endl;
//                 } else {
//                     std::string closestDate = findClosestDate(date);
//                     if (closestDate.empty()) {
//                         std::cerr << "Error: no matching date in database." << std::endl;
//                     } else {
//                         float exchangeRate = _data[closestDate];
//                         std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
//                     }
//                 }
//             } catch (const std::exception&) {
//                 std::cerr << "Error: bad input => " << line << std::endl;
//             }
//         }
//     }
//     file.close();
//     return true;
// }

// // Überprüft, ob das Datum korrekt formatiert ist und gültig ist
// bool BitcoinExchange::isValidDate(const std::string& date) {
//     std::istringstream ss(date);
//     std::string yearStr, monthStr, dayStr;
//     if (std::getline(ss, yearStr, '-') && std::getline(ss, monthStr, '-') && std::getline(ss, dayStr)) {
//         int year = std::stoi(yearStr);
//         int month = std::stoi(monthStr);
//         int day = std::stoi(dayStr);

//         if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31) {
//             return false;
//         }
//         if (month == 2) {
//             if (isLeapYear(year)) {
//                 return day <= 29;
//             } else {
//                 return day <= 28;
//             }
//         }
//         if (month == 4 || month == 6 || month == 9 || month == 11) {
//             return day <= 30;
//         }
//         return true;
//     }
//     return false;
// }

// // Überprüft, ob das Jahr ein Schaltjahr ist
// bool BitcoinExchange::isLeapYear(int year) {
//     if (year % 4 == 0) {
//         if (year % 100 == 0) {
//             return (year % 400 == 0);
//         }
//         return true;
//     }
//     return false;
// }

// // Sucht das nächstniedrigere Datum in der Datenbank
// std::string BitcoinExchange::findClosestDate(const std::string& date) {
//     std::map<std::string, float>::iterator it = _data.lower_bound(date);
//     if (it == _data.end() || it->first != date) {
//         if (it == _data.begin()) {
//             return "";
//         }
//         --it;
//     }
//     return it->first;
// }




























































#include "BitcoinExchange.hpp"

// Default Constructor
BitcoinExchange::BitcoinExchange() = default;

// Parameterized Constructor: loads the database from the CSV file
BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
    if (!parseDatabase(dbFile)) {
        std::cerr << "Error: could not open or parse data file." << std::endl;
    }
}

// Copy Constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data) {}

// Copy Assignment Operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) { // Self-assignment check
        _data = other._data;
    }
    return *this;
}

// Move Constructor
BitcoinExchange::BitcoinExchange(BitcoinExchange&& other) noexcept : _data(std::move(other._data)) {}

// Move Assignment Operator
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange&& other) noexcept {
    if (this != &other) { // Self-assignment check
        _data = std::move(other._data);
    }
    return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange() = default;

// Reads and parses the CSV database
bool BitcoinExchange::parseDatabase(const std::string& dbFile) {
    std::ifstream file(dbFile);
    if (!file.is_open()) {
        return false;
    }
    std::string line;
    std::getline(file, line); // Ignore header line
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string rate;
        if (std::getline(ss, date, ',') && std::getline(ss, rate)) {
            try {
                float exchangeRate = std::stof(rate);
                _data[date] = exchangeRate;
            } catch (const std::exception&) {
                std::cerr << "Error: invalid format in data file." << std::endl;
                return false;
            }
        }
    }
    file.close();
    return true;
}

// Checks if an input file exists and processes it
bool BitcoinExchange::processInput(const std::string& inputFile) {
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }
    std::string line;
    std::getline(file, line); // Ignore header line
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string valueStr;
        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
            date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1); // Trim whitespace
            valueStr.erase(0, valueStr.find_first_not_of(" \t\n\r\f\v"));

            try {
                float value = std::stof(valueStr);
                if (value < 0) {
                    std::cerr << "Error: not a positive number." << std::endl;
                } 
                else if (value > 1000) {
                    std::cerr << "Error: too large a number." << std::endl;
                } 
                else if (!isValidDate(date)) {
                    std::cerr << "Error: bad input => " << date << std::endl;
                } else {
                    std::string closestDate = findClosestDate(date);
                    if (closestDate.empty()) {
                        std::cerr << "Error: no matching date in database." << std::endl;
                    } else {
                        float exchangeRate = _data[closestDate];
                        std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
                    }
                }
            } catch (const std::exception&) {
                std::cerr << "Error: bad input => " << line << std::endl;
            }
        }
    }
    file.close();
    return true;
}

// Checks if the date is correctly formatted and valid
bool BitcoinExchange::isValidDate(const std::string& date) {
    std::istringstream ss(date);
    std::string yearStr, monthStr, dayStr;
    if (std::getline(ss, yearStr, '-') && std::getline(ss, monthStr, '-') && std::getline(ss, dayStr)) {
        int year = std::stoi(yearStr);
        int month = std::stoi(monthStr);
        int day = std::stoi(dayStr);

        if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31) {
            return false;
        }
        if (month == 2) {
            if (isLeapYear(year)) {
                return day <= 29;
            } else {
                return day <= 28;
            }
        }
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            return day <= 30;
        }
        return true;
    }
    return false;
}

// Checks if the year is a leap year
bool BitcoinExchange::isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return (year % 400 == 0);
        }
        return true;
    }
    return false;
}

// Finds the closest date in the database
std::string BitcoinExchange::findClosestDate(const std::string& date) {
    auto it = _data.lower_bound(date);
    if (it == _data.end() || it->first != date) {
        if (it == _data.begin()) {
            return "";
        }
        --it;
    }
    return it->first;
}
