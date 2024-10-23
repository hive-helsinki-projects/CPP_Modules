/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:12:01 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/23 10:20:59 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include "Data.hpp"

class Serializer {
private:
    Serializer();
    Serializer(Serializer const&);
    Serializer& operator=(Serializer const&);
    ~Serializer();
public:
    // Method to serialize a Data struct
    static uintptr_t serialize(Data* ptr);
    
    // Method to deserialize a Data struct
    static Data* deserialize(uintptr_t raw);
};

#endif