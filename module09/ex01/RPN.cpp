#include "RPN.hpp"
#include <sstream>
#include <cctype> // for isdigit

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

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

int stringToInt(const std::string& token) {
    std::stringstream ss(token);
    int number;
    ss >> number;
    return number;
}

bool RPN::isValidNumber(const std::string& token) const {
    // Check if the token is a single digit
    if (token.size() != 1 || !isdigit(token[0])) {
        return false;
    }

    // Convert token to an integer and check the range
    int number = token[0] - '0';
    return number >= 0 && number <= 9;
}

bool RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isValidNumber(token)) {
            _stack.push(stringToInt(token));
        } else if (isOperator(token)) {
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

    std::cout << _stack.top() << std::endl;
    return true;
}
