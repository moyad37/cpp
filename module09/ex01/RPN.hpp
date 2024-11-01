// #ifndef RPN_HPP
// #define RPN_HPP

// #include <iostream>
// #include <stack>
// #include <sstream>
// #include <string>

// class RPN {
// public:
//     RPN();
//     ~RPN();

//     bool evaluate(const std::string& expression);
    
// private:
//     std::stack<int> _stack;

//     bool isOperator(const std::string& token) const;
//     bool performOperation(const std::string& operatorToken);
// };

// #endif
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

class RPN {
public:
    // Orthodox Canonical Form für C++98
    RPN();                             // Default constructor
    RPN(const RPN& other);             // Copy constructor
    RPN& operator=(const RPN& other);  // Copy assignment operator
    ~RPN();                            // Destructor

    bool evaluate(const std::string& expression);
    
private:
    std::stack<int> _stack;

    bool isOperator(const std::string& token) const;
    bool performOperation(const std::string& operatorToken);
};

#endif
