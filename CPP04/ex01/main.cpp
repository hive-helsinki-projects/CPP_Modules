/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 07:18:37 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/11 15:42:47 by lkilpela         ###   ########.fr       */
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

    std::cout << GREEN << "~Modifying Original..." << RESET << std::endl;
    // Modify the original Dog's Brain
    originalDog.getBrain()->ideas[0] = "Modified idea";

    std::cout << GREEN << "~Checking Copy..." << RESET << std::endl;
    // Check if the copied Dog's Brain is unaffected
    if (copiedDog.getBrain()->ideas[0] == "Original idea") {
        std::cout << "Dog deep copy test passed." << std::endl;
    } else {
        std::cout << "Dog deep copy test failed." << std::endl;
    }
    std::cout << GREEN << "~End of Dog Deep Copy Test" << RESET << std::endl;
}

void testCatDeepCopy() {
    std::cout << GREEN << "~Calling Constructor..." << RESET << std::endl;
    Cat originalCat;

    std::cout << GREEN << "\n~Getting Copy..." << RESET << std::endl;
    originalCat.getBrain()->ideas[0] = "Original idea";

    Cat copiedCat = originalCat; // Using copy constructor

    std::cout << GREEN << "~Modifying Original..." << RESET << std::endl;
    // Modify the original Cat's Brain
    originalCat.getBrain()->ideas[0] = "Modified idea";

    std::cout << GREEN << "~Checking Copy..." << RESET << std::endl;
    // Check if the copied Cat's Brain is unaffected
    if (copiedCat.getBrain()->ideas[0] == "Original idea") {
        std::cout << "Cat deep copy test passed." << std::endl;
    } else {
        std::cout << "Cat deep copy test failed." << std::endl;
    }
    std::cout << GREEN << "~End of Cat Deep Copy Test" << RESET << std::endl;
    
}

void testDogCopyInScope() {
    std::cout << GREEN << "~Calling Constructor..." << RESET << std::endl;
    Dog basic;
    {
        Dog tmp = basic; // Using copy constructor
        std::cout << GREEN << "~Scope Ends for tmp" << RESET << std::endl;
    } // tmp goes out of scope here
    std::cout << GREEN << "~End of Dog Deep In Scope" << RESET << std::endl;
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
    const int   numAnimals = 10;
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

