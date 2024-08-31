/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:33:09 by mmanssou          #+#    #+#             */
/*   Updated: 2024/08/31 16:57:51 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
validateName(name);
    validateGrade(grade);
}
Bureaucrat::~Bureaucrat() {}


const std::string& Bureaucrat::getName() const {
    return name;
}
int Bureaucrat::getGrade() const {
    return grade;
}


void Bureaucrat ::incrementGrade() {
    validateGrade( grade - 1);
    grade--;
}

void Bureaucrat ::decrementGrade() {
    validateGrade( grade + 1);
    grade++;
}


const char* Bureaucrat::GradeTooHighException::what() const throw () {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw () {
    return "Grade is too low";
}

const char* Bureaucrat::InvalidNameException::what() const throw () {
    return "Name cannot be empty";
}

const char* Bureaucrat::GradeMaxInt::what() const throw() {
    return "Grade is more than Max Int";
}

void Bureaucrat::validateGrade(int grade) const {
    if(grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    } else if (grade > std::numeric_limits<int>::max()) {
        throw GradeMaxInt();
    }
}

void Bureaucrat::validateName(const std::string& name) const {
    if(name.empty())
    {
        throw InvalidNameException();
    }
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}