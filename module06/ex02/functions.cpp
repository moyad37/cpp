/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:58:55 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/12 20:01:11 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void) {

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
    if (dynamic_cast<A *>(p))
        std::cout << "Type A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Type B" << std::endl;    
    else if (dynamic_cast<C *>(p))
        std::cout << "Type C" << std::endl;     
    else
        std::cout << "unknown Type" << std::endl;
        
}
        
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type A" << std::endl;
    } catch (const std::exception&) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "Type B" << std::endl;
        } catch (const std::exception&) {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "Type C" << std::endl;
            } catch (const std::exception&) {
                std::cout << "unknown Type" << std::endl;
            }
        }
    }
}