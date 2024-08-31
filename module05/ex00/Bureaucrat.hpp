/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:58:27 by mmanssou          #+#    #+#             */
/*   Updated: 2024/08/31 16:58:28 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <limits>

class Bureaucrat {
public:
    Bureaucrat();

    Bureaucrat(const std::string& name, int grade);

    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);

    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class InvalidNameException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeMaxInt : public std::exception {
    public:
        const char* what() const throw();
    };

private:
    const std::string name;
    int grade;

    void validateGrade(int grade) const;
    void validateName(const std::string& name) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif