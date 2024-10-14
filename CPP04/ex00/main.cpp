/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 07:18:37 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/14 13:02:49 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testAnimalSound() {
    std::cout << GREEN << "~Calling Constructor..." << RESET << std::endl;
    const Animal* meta = new Animal();
    const Animal* i = new Dog();
    const Animal* j = new Cat();

    std::cout << GREEN << "\n~Getting Animal Type..." << RESET << std::endl;
    std::cout << meta->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    std::cout << j->getType() << std::endl;
    
    std::cout << GREEN << "\n~Getting Animal Sound..." << RESET << std::endl;
    meta->makeSound();
    i->makeSound();
    j->makeSound();

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
    std::cout << meta->getType() << std::endl;
    std::cout << i->getType() << std::endl;

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