/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:19:45 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/25 22:35:34 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

#define MAX_VAL 5

int main() {
    Array<char> tab1(MAX_VAL);

    // Sicherstellen, dass die Grenzen überprüft werden
    try {
        for (int i = 0; i != MAX_VAL; i++) {
            tab1[i] = 'A' + i; // Innerhalb der Grenzen
        }
       
    }
    catch (const Array<char>::OutOfBoundsException& e) {
        std::cerr << "Error: " << e.what() << std::endl;  // Gibt eine Fehlermeldung zurück
    }

    // Weiter mit dem normalen Programmablauf
    Array<char> copy1 = tab1;

    // Ausgabe der Werte
    for (int i = 0; i != MAX_VAL; i++) {
        std::cout << "tab1[" << i << "] = " << tab1[i] << std::endl;
        std::cout << "copy1[" << i << "] = " << copy1[i] << std::endl;
    }

    std::cout << std::endl;

    // Ändere das Original und überprüfe, ob die Kopie nicht betroffen ist
    for (int i = 0; i != MAX_VAL; i++) {
        tab1[i] = 'a' + i;
    }

    Array<char> copy2 = tab1;

    // Ausgabe der Werte nach Änderungen
    for (int i = 0; i != MAX_VAL; i++) {
        std::cout << "tab1[" << i << "] = " << tab1[i] << std::endl;
        std::cout << "copy1[" << i << "] = " << copy1[i] << std::endl;
        std::cout << "copy2[" << i << "] = " << copy2[i] << std::endl;
    }

    return 0;
}
