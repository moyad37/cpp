#include "RPN.hpp"
#include <sstream>

// Konstruktor
RPN::RPN() {}

// Destruktor
RPN::~RPN() {}

// Überprüft, ob ein Token ein Operator ist
bool RPN::isOperator(const std::string& token) const {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

// Führt die Operation auf den obersten zwei Elementen des Stacks durch
bool RPN::performOperation(const std::string& operatorToken) {
    if (_stack.size() < 2) {
        std::cerr << "Error: insufficient values for operation." << std::endl;
        return false;
    }

    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();
    
    if (operatorToken == "+") {
        _stack.push(a + b);
    } else if (operatorToken == "-") {
        _stack.push(a - b);
    } else if (operatorToken == "*") {
        _stack.push(a * b);
    } else if (operatorToken == "/") {
        if (b == 0) {
            std::cerr << "Error: division by zero." << std::endl;
            return false;
        }
        _stack.push(a / b);
    } else {
        std::cerr << "Error: invalid operator." << std::endl;
        return false;
    }

    return true;
}

// String zu Integer konvertieren
int stringToInt(const std::string& token) {
    std::stringstream ss(token);
    int number;
    ss >> number;
    return number;
}

// Bewertet den RPN-Ausdruck
bool RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            // Zahl auf den Stack pushen
            _stack.push(stringToInt(token));
        } else if (isOperator(token)) {
            // Operation durchführen
            if (!performOperation(token)) {
                return false;
            }
        } else {
            std::cerr << "Error: invalid token." << std::endl;
            return false;
        }
    }

    if (_stack.size() != 1) {
        std::cerr << "Error: invalid expression." << std::endl;
        return false;
    }

    // Ausgabe des Ergebnisses
    std::cout << _stack.top() << std::endl;
    return true;
}

