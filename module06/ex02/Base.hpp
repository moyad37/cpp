/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:57:23 by mmanssou          #+#    #+#             */
/*   Updated: 2024/09/05 14:03:48 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
    virtual ~Base();  // Virtueller Destruktor
    virtual void identify() const = 0; // Virtuelle Methode für Typ-Erkennung
};

#endif
