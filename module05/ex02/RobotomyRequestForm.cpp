#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!isSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecGrade()) {
        throw GradeTooLowException();
    }
    if (rand() % 2 == 0) {
        std::cout << target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "Robotomy failed for " << target << "." << std::endl;
    }
}
