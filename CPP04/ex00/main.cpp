/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 07:18:37 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/22 18:10:59 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Wrong.hpp"

#define GREEN "\033[0;32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define RESET "\033[0m"

void testAnimalSound() {
    std::cout << GREEN << "~Calling Constructor..." << RESET << std::endl;
    const Animal* meta = new Animal();
    const Animal* i = new Dog();
    const Animal* j = new Cat();

    std::cout << GREEN << "\n~Getting Animal Type..." << RESET << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    
    std::cout << GREEN << "\n~Getting Animal Sound..." << RESET << std::endl;
    i->makeSound(); //will output the dog sound!
    j->makeSound();
    meta->makeSound();

    std::cout << GREEN << "\n~Calling Destructor..." << RESET << std::endl;
    delete meta;
    delete j;
    delete i;
}

void testWrongAnimal() {
    std::cout << GREEN << "~Calling Constructor..." << RESET << std::endl;
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();

    std::cout << GREEN << "\n~Getting Animal Type..." << RESET << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << GREEN << "\n~Getting Animal Sound..." << RESET << std::endl;
    i->makeSound(); // will output the WrongAnimal sound!
    meta->makeSound();

    std::cout << GREEN << "\n~Calling Destructor..." << RESET << std::endl;
    delete meta;
    delete i;
}
int main()
{
    std::cout << BLUE << "\nTesting Animal..." << RESET << std::endl;
    testAnimalSound();
    std::cout << BLUE << "\nTesting WrongAnimal..." << RESET << std::endl;
    testWrongAnimal();

    return 0;
}