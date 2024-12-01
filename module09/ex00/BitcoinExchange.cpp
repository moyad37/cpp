
#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() = default;


BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
    if (!parseDatabase(dbFile)) {
        std::cerr << "Error: could not open or parse data file." << std::endl;
    }
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data) {}


BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _data = other._data;
    }
    return *this;
}


BitcoinExchange::BitcoinExchange(BitcoinExchange&& other) noexcept : _data(std::move(other._data)) {}


BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange&& other) noexcept {
    if (this != &other) { 
        _data = std::move(other._data);
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() = default;

bool BitcoinExchange::parseDatabase(const std::string& dbFile) {
    std::ifstream file(dbFile);
    if (!file.is_open()) {
        return false;
    }
    std::string line;
    std::getline(file, line);
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

void trim(std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    if (start == std::string::npos || end == std::string::npos) {
        str.clear();
    } else {
        str = str.substr(start, end - start + 1);
    }
}

bool isValidDateFormat(const std::string& date) {
    if (date.length() != 10) return false;
    // Check for correct positions of '-'
    if (date[4] != '-' || date[7] != '-') return false;
    // Ensure all other characters are digits
    for (size_t i = 0; i < date.length(); ++i) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return false;
    }
    return true;
}


bool isNumeric(const std::string& str) {
    if (str.empty()) return false;
    size_t i = 0;
    // Check for optional negative sign
    if (str[0] == '-') {
        if (str.length() == 1) return false; // Just "-" is not a number
        i = 1;
    }
    bool hasDot = false;
    for (; i < str.length(); ++i) {
        if (str[i] == '.') {
            if (hasDot) return false; // Multiple dots are invalid
            hasDot = true;
        } else if (!isdigit(str[i])) {
            return false; // Non-digit character found
        }
    }
    return true;
}


bool BitcoinExchange::processInput(const std::string& inputFile) {
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line); // Ignore header line
    while (std::getline(file, line)) {
        trim(line);  // Trimme die Zeile, um Leerzeichen am Anfang und Ende zu entfernen

        // Wenn die Zeile nach dem Trimmen leer ist, überspringe sie
        if (line.empty()) {
            continue;
        }

        size_t pipePos = line.find('|');

        // Check if there's a '|' separator
        if (pipePos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 1);

        // Trim whitespace from both parts
        trim(date);
        trim(valueStr);

        // Validate the date format manually
        if (!isValidDateFormat(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        // Check for multiple or missing values
        if (line.find('|', pipePos + 1) != std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Validate the value
        if (valueStr.empty()) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!isNumeric(valueStr)) {
            std::cerr << "Error: bad input => " << valueStr << std::endl;
            continue;
        }

        // Process the value and validate range
        try {
            float value = std::stof(valueStr);
            if (value < 0) {
                std::cerr << "Error: not a positive number." << std::endl;
            } else if (value > 1000) {
                std::cerr << "Error: too large a number." << std::endl;
            } else if (!isValidDate(date)) {
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
    file.close();
    return true;
}


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

bool BitcoinExchange::isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return (year % 400 == 0);
        }
        return true;
    }
    return false;
}

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

//for test
// date | value
// 2011-01-03 | 3
// 2011-01-03 | 2
// 2011-01-03 | 1
// 2011-01-03 | 1.2
// 2011-01-09 | 1
// 2012-01-11 | -1
// 2001-42-42
// 2012-01-11 | 1
// 2012-01-11 | 2147483648
// 2011-01-03 | -5
// 2011-01-09 | 1500
// 2011-13-03 | 5
// 2011-02-29 | 3
// 2026-01-03 | 3