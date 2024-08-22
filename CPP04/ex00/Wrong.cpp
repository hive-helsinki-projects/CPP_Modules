/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:23:32 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/22 12:42:24 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wrong.hpp"

// WronngAnimal implementation

WrongAnimal::WrongAnimal() : type("Default") {
    std::cout << "WrongAnimal default constructed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructed." << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}

// WronngCat implementation

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat default constructed." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    std::cout << "WrongCat assigned." << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructed." << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Meow!" << std::endl;  // This will not be used in polymorphism
}