/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:33:35 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/12 19:38:22 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {

    Data data;
    data.name = "John Doe";
    data.age = 30;

    std::cout << "Original Data:" << std::endl;
    std::cout << "Name: " << data.name << ", Age: " << data.age << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized data (uintptr_t): " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "Name: " << deserializedData->name << ", Age: " << deserializedData->age << std::endl;

    if (&data == deserializedData) {
        std::cout << "Pointers match, serialization and deserialization successful!" << std::endl;
    } else {
        std::cout << "Pointers do not match, something went wrong!" << std::endl;
    }

    return 0;
}

