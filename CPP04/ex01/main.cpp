/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 07:18:37 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/14 15:47:03 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void testDogDeepCopy() {
    std::cout << "--------------------------------" << std::endl;
    std::cout << BLUE << "[BEFORE MODIFICATION]" << RESET << std::endl;
    std::cout << GREEN << " 1. ORIGINAL DOG" << std::endl << RESET;
    Dog originalDog;
    originalDog.getBrain()->ideas[0] = "APPLE";
    std::cout << " Brain's Idea: " << originalDog.getBrain()->ideas[0] << std::endl;
    
    std::cout << GREEN << "2. COPIED DOG" << RESET << std::endl;
    Dog copiedDog = originalDog; // Using copy constructor
    std::cout << "  Brain's Idea: " << copiedDog.getBrain()->ideas[0] << std::endl;
    std::cout << "--------------------------------" << std::endl;
    
    std::cout << BLUE << "[AFTER MODIFICATION]" << RESET << std::endl;
    std::cout << GREEN << "1. ORIGINAL DOG" << std::endl << RESET;
    originalDog.getBrain()->ideas[0] = "BANANA";
    std::cout << "  Brain's Idea: " << originalDog.getBrain()->ideas[0] << std::endl;

    std::cout << GREEN << "2. COPIED DOG" << RESET << std::endl;
    std::cout << "  Brain's Idea: " << copiedDog.getBrain()->ideas[0] << std::endl;
    std::cout << "--------------------------------" << std::endl;

    std::cout << GREEN << "~End of Dog Deep Copy Test" << RESET << std::endl;
}

void testCatDeepCopy() {
    std::cout << "--------------------------------" << std::endl;
    std::cout << BLUE << "[BEFORE MODIFICATION]" << RESET << std::endl;
    std::cout << GREEN << " 1. ORIGINAL CAT" << std::endl << RESET;
    Cat originalCat;
    originalCat.getBrain()->ideas[0] = "TREE";
    std::cout << " Brain's Idea: " << originalCat.getBrain()->ideas[0] << std::endl;

    std::cout << GREEN << "2. COPIED CAT" << RESET << std::endl;
    Cat copiedCat = originalCat; // Using copy constructor
    std::cout << "  Brain's Idea: " << copiedCat.getBrain()->ideas[0] << std::endl;
    std::cout << "--------------------------------" << std::endl;
    
    std::cout << BLUE << "[AFTER MODIFICATION]" << RESET << std::endl;
    std::cout << GREEN << "1. ORIGINAL CAT" << std::endl << RESET;
    originalCat.getBrain()->ideas[0] = "MOUSE";
    std::cout << "  Brain's Idea: " << originalCat.getBrain()->ideas[0] << std::endl;

    // Check if the copied Cat's Brain is unaffected
    std::cout << GREEN << "2. COPIED CAT" << RESET << std::endl;
    std::cout << "  Brain's Idea: " << copiedCat.getBrain()->ideas[0] << std::endl;
    std::cout << "--------------------------------" << std::endl;
    
    std::cout << GREEN << "~End of Cat Deep Copy Test" << RESET << std::endl;
    
}

void testDogCopyInScope() {
    std::cout << GREEN << "~Calling Constructor..." << RESET << std::endl;
    Dog basic;
    {
        Dog tmp = basic; // Using copy constructor
        std::cout << GREEN << "~Scope Ends for tmp" << RESET << std::endl;
    } // tmp goes out of scope here
    std::cout << GREEN << "~End of Dog Copy In Scope" << RESET << std::endl;
}

void createAnimal(int numAnimals, Animal* animals[])
{
    for (int i = 0; i < numAnimals; ++i) {
        if (i < numAnimals / 2) {
            std::cout << GREEN << "[DOG] " << i << std::endl << RESET;
            animals[i] = new Dog();
        } else {
            std::cout << GREEN << "[CAT] " << i << std::endl << RESET;
            animals[i] = new Cat();
        }
    }
}

void deleteAnimal(int numAnimals, Animal* animals[])
{
        // Delete all animals
    for (int i = 0; i < numAnimals; ++i) {
        std::cout << RED << "[DELETING] " << i << std::endl << RESET;
        delete animals[i];
    }
}
int main()
{
    const int   numAnimals = 4;
    Animal*     animals[numAnimals];
    
    std::cout << BLUE << "\nCalling Constructor to Create and Fill the Array of Animal Objects..." << RESET << std::endl;
    createAnimal(numAnimals, animals);
    
    std::cout << BLUE << "\nTesting Dog Deep Copy..." << RESET << std::endl;
    testDogDeepCopy();
        
    std::cout << BLUE << "\nTesting Cat Deep Copy..." << RESET << std::endl;
    testCatDeepCopy();
    
    std::cout << BLUE << "\nTesting Dog Copy In Scope..." << RESET << std::endl;
    testDogCopyInScope();
    
    std::cout << GREEN << "\n~Calling Destructor to Delete the Array of Animal Objects..." << RESET << std::endl;
    deleteAnimal(numAnimals, animals);

    // Check for memory leaks
    return 0;
}

