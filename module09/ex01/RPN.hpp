
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

class RPN {
public:

    RPN();                            
    RPN(const RPN& other);            
    RPN& operator=(const RPN& other); 
    ~RPN();                           

    bool evaluate(const std::string& expression);
    
private:
    std::stack<int> _stack;

    bool isOperator(const std::string& token) const;
    bool performOperation(const std::string& operatorToken);
    bool isValidNumber(const std::string& token) const;
};

#endif
