#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

private:
    const std::string name;
    bool signedStatus;
    const int gradeToSign;
    const int gradeToExecute;

    void validateGrade(int grade) const;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
