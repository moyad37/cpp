/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:33:35 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/05 13:51:21 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
    // Create a Data object
    Data data;
    data.name = "John Doe";
    data.age = 30;

    // Print original Data
    std::cout << "Original Data:" << std::endl;
    std::cout << "Name: " << data.name << ", Age: " << data.age << std::endl;

    // Serialize the Data object pointer to unsigned long
    unsigned long raw = Serializer::serialize(&data);
    std::cout << "Serialized data (unsigned long): " << raw << std::endl;

    // Deserialize it back to Data*
    Data* deserializedData = Serializer::deserialize(raw);

    // Print deserialized Data
    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "Name: " << deserializedData->name << ", Age: " << deserializedData->age << std::endl;

    // Ensure that the original pointer and deserialized pointer are the same
    if (&data == deserializedData) {
        std::cout << "Pointers match, serialization and deserialization successful!" << std::endl;
    } else {
        std::cout << "Pointers do not match, something went wrong!" << std::endl;
    }

    return 0;
}

