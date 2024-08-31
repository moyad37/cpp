#include "Bureaucrat.hpp"

// Default Constructor
Bureaucrat::Bureaucrat() : name("Unnamed"), grade(150) {}

// Parameterized Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
    validateName(name);
    validateGrade(grade);
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

// Copy Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        grade = other.grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Getter for name
const std::string& Bureaucrat::getName() const {
    return name;
}

// Getter for grade
int Bureaucrat::getGrade() const {
    return grade;
}

// Increment grade
void Bureaucrat::incrementGrade() {
    if (grade <= 1) {
        throw GradeTooHighException();
    }
    --grade;
}

// Decrement grade
void Bureaucrat::decrementGrade() {
    if (grade >= 150) {
        throw GradeTooLowException();
    }
    ++grade;
}

// Sign a form
void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

// Execute a form
void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << this->getName() << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

// Exception messages
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* Bureaucrat::InvalidNameException::what() const throw() {
    return "Invalid name!";
}

// Validate grade
void Bureaucrat::validateGrade(int grade) const {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

// Validate name
void Bureaucrat::validateName(const std::string& name) const {
    if (name.empty()) {
        throw InvalidNameException();
    }
}

// Overloading << operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
