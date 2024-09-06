/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:58:55 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/06 21:47:39 by mmanssou         ###   ########.fr       */
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
    
    int random = rand();
    float j = random % 3;
    if (j == 0)
        return new A();
    else if (j == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p) {
    if (p)
        p->identify();
}

void identify(Base& p) {
    p.identify();
}
