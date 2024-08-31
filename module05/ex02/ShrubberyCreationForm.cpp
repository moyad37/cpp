#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!isSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecGrade()) {
        throw GradeTooLowException();
    }

    std::ofstream outFile((target + "_shrubbery").c_str()); // Use c_str() to convert std::string to const char*

    if (outFile.is_open()) {
        outFile << "ASCII Tree" << std::endl; // Simplified output
        outFile.close();
    } else {
        std::cerr << "Failed to open file for writing." << std::endl;
    }
}
