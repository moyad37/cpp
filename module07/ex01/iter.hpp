/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:06:30 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/25 13:51:26 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>


template <typename T, std::size_t N>
void iter(T (&array)[N], std::size_t length, void (*f)(const T&)) {
    if (length > N) {
        length = N;
    }
    
    for (std::size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}

#endif
