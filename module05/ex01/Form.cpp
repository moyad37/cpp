#include "Form.hpp"


Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

Form::Form(const Form& other)
    : name(other.name), signedStatus(other.signedStatus), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->signedStatus = other.signedStatus;
    }
    return *this;
}

Form::~Form() {}


const std::string& Form::getName() const {
    return name;
}

bool Form::isSigned() const {
    return signedStatus;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExecute() const {
    return gradeToExecute;
}


void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    signedStatus = true;
}


const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

void Form::validateGrade(int grade) const {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}


std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() << " requires grade " << form.getGradeToSign() << " to sign and grade " 
       << form.getGradeToExecute() << " to execute. Signed: " << (form.isSigned() ? "Yes" : "No");
    return os;
}
