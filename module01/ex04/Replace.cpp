#include "Replace.hpp"

Replace::Replace()
{
    this->haveC = false;
}

std::string Replace::replaceText(const std::string &input, const std::string target, const std::string replacement)
{
    std::string result;
    size_t start = 0;

    while (true) {
        size_t found = input.find(target, start);
        if (found != std::string::npos) {
            // Append characters between start and found position
            result += input.substr(start, found - start);
            
            // Append replacement string
            result += replacement;

            // Move start position after the found target
            start = found + target.length();
            this->haveC = true;
        } else {
            // Append the remaining characters
            result += input.substr(start);
            //std::cout << GREEN << "NOTTTTTT" << RESET << std::endl;
            break;
        }
    }
    return result;
}

Replace::~Replace()
{
    std::cout << "Destructor killed" << std::endl;
}
