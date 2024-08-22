/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 07:18:37 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/22 18:17:26 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define GREEN "\033[0;32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define RESET "\033[0m"


void testDogDeepCopy() {
    std::cout << GREEN << "~Calling Constructor..." << RESET << std::endl;
    Dog originalDog;
    
    std::cout << GREEN << "\n~Getting Copy..." << RESET << std::endl;
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

void testCatDeepCopy() {
    std::cout << GREEN << "~Calling Constructor..." << RESET << std::endl;
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

void testDogCopyInScope() {
    std::cout << GREEN << "~Calling Constructor..." << RESET << std::endl;
    Dog basic;
    {
        Dog tmp = basic; // Using copy constructor
    } // tmp goes out of scope here
}

int main()
{
    std::cout << BLUE << "Creating and filling an array of Animal objects..." << RESET << std::endl;
    const int numAnimals = 10;
    Animal* animals[numAnimals];

    // Create half Dog and half Cat objects
    for (int i = 0; i < numAnimals / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = numAnimals / 2; i < numAnimals; ++i) {
        animals[i] = new Cat();
    }

    std::cout << BLUE << "\nTesting Dog Deep Copy..." << RESET << std::endl;
    testDogDeepCopy();

    std::cout << BLUE << "\nTesting Cat Deep Copy..." << RESET << std::endl;
    testCatDeepCopy();

    std::cout << BLUE << "\nTesting Dog Copy In Scope..." << RESET << std::endl;
    testDogCopyInScope();
    
    std::cout << GREEN << "\n~Calling Destructor..." << RESET << std::endl;
    // Delete all animals
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    // Check for memory leaks
    return 0;
}

