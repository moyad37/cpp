#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 150);

        ShrubberyCreationForm formA("Home");
        RobotomyRequestForm formB("Target1");
        PresidentialPardonForm formC("Target2");

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
        std::cout << formC << std::endl;

        alice.signForm(formA);
        alice.signForm(formB);
        alice.signForm(formC);

        alice.executeForm(formA);
        alice.executeForm(formB);
        alice.executeForm(formC);

        bob.executeForm(formA); // Should fail, as Bob's grade is too low
        bob.executeForm(formB); // Should fail, as Bob's grade is too low
        bob.executeForm(formC); // Should fail, as Bob's grade is too low

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
