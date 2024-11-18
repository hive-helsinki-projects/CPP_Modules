/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:12:01 by lkilpela          #+#    #+#             */
/*   Updated: 2024/11/18 09:53:34 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Data.hpp"

class Serializer {
private:
    Serializer() = delete;
    Serializer(Serializer const&) = delete;
    Serializer& operator=(Serializer const&) = delete;
    ~Serializer() = delete;
public:
    // Method to serialize a Data struct
    static uintptr_t serialize(Data* ptr);
    
    // Method to deserialize a Data struct
    static Data* deserialize(uintptr_t raw);
};
