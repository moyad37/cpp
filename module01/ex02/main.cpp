#include <iostream>
#include <string>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"
int main() {

    std::string myString = "HI THIS IS BRAIN";
    std::string* stringPTR = &myString;
    std::string& stringREF = myString;
    std::cout << RED << "Memory address of myString: " << &myString << RESET << std::endl;
    std::cout << GREEN << "Memory address held by stringPTR: " << stringPTR << RESET << std::endl;
    std::cout << BLUE << "Memory address held by stringREF: " << &stringREF << RESET << std::endl;
    std::cout << RED << "Value of myString: " << myString << RESET << std::endl;
    std::cout << GREEN << "Value pointed to by stringPTR: " << *stringPTR << RESET << std::endl;
    std::cout << BLUE <<"Value pointed to by stringREF: " << stringREF << RESET << std::endl;
    return 0;
}
