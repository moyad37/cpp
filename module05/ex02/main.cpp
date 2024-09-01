/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:45:43 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/01 16:15:04 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

int main() {
    srand(time(0));
    try {
        Bureaucrat alice("Alice", 1);

        ShrubberyCreationForm formA("Home");
        RobotomyRequestForm formB("Target1");
        PresidentialPardonForm formC("Target2");

        std::cout << alice << std::endl;
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
        std::cout << formC << std::endl;

        alice.signForm(formA);
        alice.signForm(formB);
        alice.signForm(formC);

        alice.executeForm(formA);
        alice.executeForm(formB);
        alice.executeForm(formC);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat bob("Bob", 150);

        ShrubberyCreationForm formA("Home");
        RobotomyRequestForm formB("Target1");
        PresidentialPardonForm formC("Target2");

        std::cout << bob << std::endl;
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
        std::cout << formC << std::endl;

        bob.signForm(formA);
        bob.signForm(formB);
        bob.signForm(formC);


        bob.executeForm(formA);
        bob.executeForm(formB);
        bob.executeForm(formC);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}




