/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:43:42 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/06 22:01:31 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

class Serializer {
public:
    static unsigned long serialize(Data* ptr) {
        return reinterpret_cast<unsigned long>(ptr);
    }
    static Data* deserialize(unsigned long raw) {
        return reinterpret_cast<Data*>(raw);
    }

private:
    Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
};

#endif
