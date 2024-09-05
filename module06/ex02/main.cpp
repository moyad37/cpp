/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:58:45 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/05 14:08:02 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "functions.hpp"
#include <iostream>

int main() {
    // Teste generate()
    Base* base = generate();

    // Teste identify(Base*)
    std::cout << "identify(Base*): ";
    identify(base);

    // Teste identify(Base&)
    std::cout << "identify(Base&): ";
    identify(*base);

    // Bereinige den Speicher
    delete base;

    return 0;
}


