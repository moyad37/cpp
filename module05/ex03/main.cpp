/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:45:43 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/03 13:46:15 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
int main() {
    srand(time(0));
    try {
        Bureaucrat alice("Alice", 1);
        Intern someRandomIntern;

        AForm* formA = someRandomIntern.makeForm("shrubbery creation", "Home");
        AForm* formB = someRandomIntern.makeForm("robotomy request", "Target1");
        AForm* formC = someRandomIntern.makeForm("presidential pardon", "Target2");

        std::cout << "#####################################" << std::endl;
        std::cout << alice << std::endl;
        std::cout << "#####################################" << std::endl;
        std::cout << *formA << std::endl;
        std::cout << "#####################################" << std::endl;
        std::cout << *formB << std::endl;
        std::cout << "#####################################" << std::endl;
        std::cout << *formC << std::endl;
        std::cout << "#####################################" << std::endl;

        alice.signForm(*formA);
        alice.signForm(*formB);
        alice.signForm(*formC);

        alice.executeForm(*formA);
        alice.executeForm(*formB);
        alice.executeForm(*formC);

        delete formA;
        delete formB;
        delete formC;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat bob("Bob", 150);
        Intern someRandomIntern;

        AForm* formD = someRandomIntern.makeForm("unknown form", "TargetX");

        delete formD;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}