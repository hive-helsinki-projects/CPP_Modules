/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 07:44:16 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/22 07:55:13 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog created" << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type) {}
Dog::Dog(const Dog& other) : Animal(other) {}
Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog Class destructed." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}