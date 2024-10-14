/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 07:44:16 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/14 16:11:31 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"),
            brain(new Brain())
{
    std::cout << "Dog default constructed" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other),
                            brain(new Brain(*other.brain))
{
    std::cout << "Dog copy constructed" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        delete brain; // Ensure no memory leak
        brain = new Brain(*other.brain); // Ensure a deep copy
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout <<"Dog destructed." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
}