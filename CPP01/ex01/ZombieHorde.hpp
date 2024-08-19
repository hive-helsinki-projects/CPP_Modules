/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:38:46 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/18 18:34:07 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
#define ZOMEBIEHORDE_HPP

#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        Zombie() : name("default") {} // Default constructor
        Zombie(std::string name) : name(name) {} // Initializer List 

        ~Zombie() {
            std::cout << name << " is destroyed." << "\n";
        }
        void announce(void) {
            std::cout << name << ": BraiiiiiiinnnzzzZ..." << "\n";
        }
        void setName(std::string n) {
            name = n;
        }
};

Zombie* zombieHorde(int N, std::string name);

#endif