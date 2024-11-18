/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:54:52 by lkilpela          #+#    #+#             */
/*   Updated: 2024/11/18 12:55:33 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream> // std::cout, std::endl
#include <ctime> // time
#include <cstdlib> // srand, rand
#include "D.hpp"

// Generate a random class
Base* generate(void) {
    int random = rand() % 4;
    switch (random) {
        case 0:
            std::cout << "Generated A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated C" << std::endl;
            return new C();
        case 3: // This class is not handled by the identify functions, so it will trigger "Unknown type" message.
            std::cout << "Generated D" << std::endl;
            return new D();
    }
    return nullptr;
}

// Identify the class by pointer
void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

// Identify the class by reference
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    } catch (...) {}

    std::cout << "Unknown type" << std::endl;
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    Base* basePtr = generate();
    std::cout << "Identifying by pointer: ";
    identify(basePtr);

    std::cout << "Identifying by reference: ";
    identify(*basePtr);

    delete basePtr;
    return 0;
}