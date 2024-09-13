/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:06:30 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/09 20:06:34 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP


template <typename T, typename F>
void iter(T* array, int length, F func) {
    for (int i = 0; i < length; i++) {
        func(array[i]);
    }
}

#endif
