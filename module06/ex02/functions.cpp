/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:58:55 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/05 14:07:54 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib> // für rand() und srand()
#include <ctime>   // für time()

Base* generate(void) {
    // Initialisiere den Zufallszahlengenerator
    srand(static_cast<unsigned int>(time(0)));

    int random = rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p) {
    if (p)
        p->identify();  // Aufruf der virtuellen Methode
}

void identify(Base& p) {
    p.identify();  // Aufruf der virtuellen Methode
}
