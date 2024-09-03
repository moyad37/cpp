/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:15:07 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/03 13:36:38 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other) {}
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    const std::string formTypes[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* forms[] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };

    AForm* formToReturn = NULL;
    for (int i = 0; i < 3; ++i) {
        if (formName == formTypes[i]) {
            std::cout << "Intern creates " << formTypes[i] << " form." << std::endl;
            formToReturn = forms[i];
        } else {
            delete forms[i];
    }
    }

    if (formToReturn == NULL) {
        throw FormNotFoundException();
    }

    return formToReturn;
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Form not found!";
}
