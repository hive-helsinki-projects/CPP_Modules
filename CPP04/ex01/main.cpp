/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 07:18:37 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/22 18:10:30 by lkilpela         ###   ########.fr       */
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

    std::cout << BLUE << "\nTesting deep copies..." << RESET << std::endl;
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

void testCatDeepCopy() {
    Cat originalCat;
    originalCat.getBrain()->ideas[0] = "Original idea";

    Cat copiedCat = originalCat; // Using copy constructor

    // Modify the original Cat's Brain
    originalCat.getBrain()->ideas[0] = "Modified idea";

    // Check if the copied Cat's Brain is unaffected
    if (copiedCat.getBrain()->ideas[0] == "Original idea") {
        std::cout << "Cat deep copy test passed." << std::endl;
    } else {
        std::cout << "Cat deep copy test failed." << std::endl;
    }
}

void testDogDeepCopy() {
    Dog originalDog;
    originalDog.getBrain()->ideas[0] = "Original idea";

    Dog copiedDog = originalDog; // Using copy constructor

    // Modify the original Dog's Brain
    originalDog.getBrain()->ideas[0] = "Modified idea";

    // Check if the copied Dog's Brain is unaffected
    if (copiedDog.getBrain()->ideas[0] == "Original idea") {
        std::cout << "Dog deep copy test passed." << std::endl;
    } else {
        std::cout << "Dog deep copy test failed." << std::endl;
    }
}

void testDogCopyInScope() {
    Dog basic;
    {
        Dog tmp = basic; // Using copy constructor
    } // tmp goes out of scope here
}

int main() {
    testCatDeepCopy();
    //testDogDeepCopy();
    //testDogCopyInScope();
    return 0;
}