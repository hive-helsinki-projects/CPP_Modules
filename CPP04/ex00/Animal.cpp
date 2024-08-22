/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 07:18:49 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/22 07:47:39 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Default") {
    std::cout << "Animal default constructed." << std::endl;
}

Animal::Animal(const std::string& type) : type(type) {
    std::cout  << "Animal " << type << " constructed." << std::endl;
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

void makeSound(void) {
    
}
