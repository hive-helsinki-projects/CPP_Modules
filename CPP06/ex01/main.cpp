/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:17:34 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/18 15:19:16 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Serializer::Data originalData;
    originalData.s1 = "Hello";
    originalData.n = 42;
    originalData.s2 = "World";

    std::cout << "Original Data:" << std::endl;
    std::cout << "s1: " << originalData.s1 << std::endl;
    std::cout << "n: " << originalData.n << std::endl;
    std::cout << "s2: " << originalData.s2 << std::endl;

    uintptr_t serializedData = Serializer::serialize(&originalData);
    Serializer::Data* deserializedData = Serializer::deserialize(serializedData);

    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "s1: " << deserializedData->s1 << std::endl;
    std::cout << "n: " << deserializedData->n << std::endl;
    std::cout << "s2: " << deserializedData->s2 << std::endl;

    if (deserializedData == &originalData) {
        std::cout << "\nDeserialization successful: Pointers match." << std::endl;
    } else {
        std::cout << "\nDeserialization failed: Pointers do not match." << std::endl;
    }

    return 0;
}