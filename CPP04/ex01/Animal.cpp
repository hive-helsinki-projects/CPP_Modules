/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 07:18:49 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/22 08:03:20 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Default") {
    std::cout << "Animal default constructed." << std::endl;
}

Animal::Animal(const std::string& type) : type("Unknown") {
    std::cout  << "Animal of type " << type << " created." << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal class destructed." << std::endl;
}

void Animal::makeSound(void) const {
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
    return type;
}
