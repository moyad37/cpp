#include "AForm.hpp"

// Default Constructor
AForm::AForm() : name("Unnamed"), signedStatus(false), signGrade(150), execGrade(150) {}

// Parameterized Constructor
AForm::AForm(const std::string& name, int signGrade, int execGrade) 
    : name(name), signedStatus(false), signGrade(signGrade), execGrade(execGrade) {
    validateGrade(signGrade);
    validateGrade(execGrade);
}

// Copy Constructor
AForm::AForm(const AForm& other) 
    : name(other.name), signedStatus(other.signedStatus), signGrade(other.signGrade), execGrade(other.execGrade) {}

// Copy Assignment Operator
AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        signedStatus = other.signedStatus;
        // Note: name, signGrade, execGrade are const and can't be assigned
    }
    return *this;
}

// Destructor
AForm::~AForm() {}

// Getter for name
const std::string& AForm::getName() const {
    return name;
}

// Getter for signed status
bool AForm::isSigned() const {
    return signedStatus;
}

// Getter for sign grade
int AForm::getSignGrade() const {
    return signGrade;
}

// Getter for exec grade
int AForm::getExecGrade() const {
    return execGrade;
}

// Sign the form
void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > signGrade) {
        throw GradeTooLowException();
    }
    signedStatus = true;
}

// Exception messages
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

// Validate grade
void AForm::validateGrade(int grade) const {
    if (grade < 1 || grade > 150) {
        throw GradeTooHighException();
    }
}

// Overloading << operator
std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << form.getName() << ", sign grade " << form.getSignGrade()
       << ", execute grade " << form.getExecGrade() << ", ";
    if (form.isSigned()) {
        os << "signed";
    } else {
        os << "not signed";
    }
    return os;
}
