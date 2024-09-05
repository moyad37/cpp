/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:32:51 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/05 13:32:55 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <limits>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
    return literal == "nan" || literal == "nanf" || literal == "+inf" || 
           literal == "-inf" || literal == "+inff" || literal == "-inff";
}

bool ScalarConverter::isFloatLiteral(const std::string& literal) {
    return literal.find('f') != std::string::npos;
}

void ScalarConverter::convert(const std::string& literal) {
    // Detect if the input is a pseudo literal
    if (isPseudoLiteral(literal)) {
        if (literal == "nan" || literal == "nanf") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        } else {
            std::string sign = (literal[0] == '-') ? "-" : "+";
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << sign << "inff" << std::endl;
            std::cout << "double: " << sign << "inf" << std::endl;
        }
        return;
    }

    // Try to convert to double first
    char* end;
    double value = std::strtod(literal.c_str(), &end);

    if (*end && *end != 'f') {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // Print as char, int, float, and double
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::printChar(double value) {
    if (std::isnan(value) || std::isinf(value) || value < CHAR_MIN || value > CHAR_MAX) {
        std::cout << "char: impossible" << std::endl;
    } else if (!isprint(static_cast<int>(value))) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
}

void ScalarConverter::printInt(double value) {
    if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}

void ScalarConverter::printFloat(double value) {
    std::cout << "float: " << static_cast<float>(value);
    if (static_cast<float>(value) == static_cast<int>(value)) {
        std::cout << ".0";
    }
    std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double value) {
    std::cout << "double: " << value;
    if (value == static_cast<int>(value)) {
        std::cout << ".0";
    }
    std::cout << std::endl;
}
