/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 07:41:09 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/14 16:11:52 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructor and initialization list
Cat::Cat() : AAnimal("Cat"), 
            brain(new Brain())
{
    std::cout << "Cat default constructed." << std::endl;
}


Cat::Cat(const Cat& other) : AAnimal(other),
                            brain(new Brain(*other.brain))
{
    std::cout << "Cat copy constructed." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        delete brain; // Ensure no memory leak
        brain = new Brain(*other.brain); // Ensure a deep copy
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructed." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
    return brain;
}