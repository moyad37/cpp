/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:58:20 by mmanssou          #+#    #+#             */
/*   Updated: 2024/08/31 16:58:25 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("gr", 3443);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << bob << std::endl;

        bob.incrementGrade();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat joe("Joe", 149);
        std::cout << joe << std::endl;

        joe.decrementGrade();
        std::cout << joe << std::endl;

        joe.incrementGrade();
        std::cout << joe << std::endl;

        joe.decrementGrade();
        std::cout << joe << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
