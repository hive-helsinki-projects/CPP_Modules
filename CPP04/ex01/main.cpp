/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 07:18:37 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/22 09:05:53 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    const int numAnimals = 10;
    Animal* animals[numAnimals];

    // Create half Dog and half Cat objects
    for (int i = 0; i < numAnimals / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = numAnimals / 2; i < numAnimals; ++i) {
        animals[i] = new Cat();
    }

    // Test deep copy
    Dog originalDog;
    originalDog.getBrain()->ideas[0] = "Original idea";
    Dog copiedDog = originalDog;
    copiedDog.getBrain()->ideas[0] = "Copied idea";

    std::cout << "..." << std::endl;
    std::cout << "Original Dog's idea: " << originalDog.getBrain()->ideas[0] << std::endl;
    std::cout << "Copied Dog's idea: " << copiedDog.getBrain()->ideas[0] << std::endl;
    std::cout << "..." << std::endl;

    // Delete all animals
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    // Check for memory leaks
    return 0;
}