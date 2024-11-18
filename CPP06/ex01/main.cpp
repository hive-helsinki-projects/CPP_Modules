/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:17:34 by lkilpela          #+#    #+#             */
/*   Updated: 2024/11/18 09:54:31 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
    Data originalData;
    originalData.s = "Hello World";
    originalData.n = 42;

    std::cout << "Original Data:" << std::endl;
    std::cout << "s: " << originalData.s << std::endl;
    std::cout << "n: " << originalData.n << std::endl;

    uintptr_t serializedData = Serializer::serialize(&originalData);
    std::cout << "\nSerialized Address: " << &originalData << std::endl;
    
    Data* deserializedData = Serializer::deserialize(serializedData);
    std::cout << "Deserialized Adress: " << deserializedData << std::endl;

    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "s: " << deserializedData->s << std::endl;
    std::cout << "n: " << deserializedData->n << std::endl;

    if (deserializedData == &originalData) {
        std::cout << "\nDeserialization successful: Pointers match." << std::endl;
    } else {
        std::cout << "\nDeserialization failed: Pointers do not match." << std::endl;
    }

    return 0;
}