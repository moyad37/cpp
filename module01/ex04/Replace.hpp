

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

#ifndef REPLACE_H
# define REPLACE_H

class Replace
{
private:
    
public:
    bool haveC;
    void processFiles(const std::string& inputFileName, const std::string& outputFileName, const std::string& s1, const std::string& s2);
    std::string replaceText(const std::string &line, const std::string str1, const std::string str2);
    Replace();
    ~Replace();
};

//std::string replaceText(const std::string &line, const std::string str1, const std::string str2);
//bool check(const std::string &input, const std::string target);

#endif
