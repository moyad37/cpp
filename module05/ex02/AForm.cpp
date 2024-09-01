/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:45:08 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/01 15:56:44 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm() : name("Unnamed"), signedStatus(false), signGrade(150), execGrade(150) {}


AForm::AForm(const std::string& name, int signGrade, int execGrade) 
    : name(name), signedStatus(false), signGrade(signGrade), execGrade(execGrade) {
    validateGrade(signGrade);
    validateGrade(execGrade);
}


AForm::AForm(const AForm& other) 
    : name(other.name), signedStatus(other.signedStatus), signGrade(other.signGrade), execGrade(other.execGrade) {}


AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        signedStatus = other.signedStatus;
    }
    return *this;
}


AForm::~AForm() {}

const std::string& AForm::getName() const {
    return name;
}

bool AForm::isSigned() const {
    return signedStatus;
}

int AForm::getSignGrade() const {
    return signGrade;
}

int AForm::getExecGrade() const {
    return execGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > signGrade) {
        throw GradeTooLowException();
    }
    signedStatus = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

void AForm::validateGrade(int grade) const {
    if (grade < 1 || grade > 150) {
        throw GradeTooHighException();
    }
}


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
