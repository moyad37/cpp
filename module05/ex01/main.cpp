#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);
        
        std::cout << alice << std::endl;
        
        Form formA("FormA", 50, 75);
        Form formB("FormB", 10, 20);
        
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        alice.signForm(formA);

        alice.signForm(formB);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {

        Bureaucrat bob("Bob", 150);
        std::cout << bob << std::endl;
        Form formA("FormA", 50, 75);
        Form formB("FormB", 10, 20);
        bob.signForm(formB);
        bob.signForm(formA);
    }
     catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
