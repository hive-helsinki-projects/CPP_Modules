/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:29:53 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/14 13:03:20 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// WrongCat implementation
WrongCat::WrongCat() : WrongAnimal("WrongCat") {
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

