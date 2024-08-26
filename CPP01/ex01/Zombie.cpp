/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:11:38 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/26 09:34:24 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("default") {} // Default constructor
Zombie::Zombie(std::string name) : name(name) {} // Initializer List 

Zombie::~Zombie() {
    std::cout << name << " is destroyed.\n";
}
void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << "\n";
}
void Zombie::setName(std::string n) {
    name = n;
}