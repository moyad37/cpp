/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:43:42 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/05 13:51:13 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

class Serializer {
public:
    // Serialize: Convert a pointer to an unsigned long (C++98 compatible)
    static unsigned long serialize(Data* ptr) {
        return reinterpret_cast<unsigned long>(ptr);
    }

    // Deserialize: Convert the unsigned long back to a pointer
    static Data* deserialize(unsigned long raw) {
        return reinterpret_cast<Data*>(raw);
    }

private:
    // Prevent instantiation
    Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
};

#endif
