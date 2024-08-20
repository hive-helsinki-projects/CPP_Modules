/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:37:17 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/20 19:40:47 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

Zombie::Zombie() : name("default") {} // Default constructor
Zombie::Zombie(std::string name) : name(name) {} // Initializer List 

Zombie::~Zombie() {
    std::cout << name << " is destroyed." << "\n";
}
void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << "\n";
}
void Zombie::setName(std::string n) {
    name = n;
}

Zombie* zombieHorde(int N, std::string name) {
    if (N <=0) return nullptr;
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }
    return (horde);
}