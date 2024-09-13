/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:58:45 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/06 22:02:40 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "functions.hpp"
#include <iostream>

int main() {
    Base* base = generate();

    std::cout << "identify(Base*): ";
    identify(base);

    std::cout << "identify(Base&): ";
    identify(*base);

    delete base;

    return 0;
}


