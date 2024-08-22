/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 07:18:49 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/22 19:12:20 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Default") {
    std::cout << "Animal default constructed." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "Animal destructed." << std::endl;
}

std::string AAnimal::getType() const {
    return type;
}
