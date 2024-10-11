/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:33:38 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/11 14:08:38 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap " << getName() << " created by default constructor." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name) {
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout  << "ScavTrap " << name << " created by parameterized constructor." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap " << getName() << " created by copy constructor." << std::endl;
}
    
ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << getName() << " destroyed." << std::endl; 
}

void ScavTrap::attack(const std::string& target) {
    std::cout << RED << "[ATTACK] " << RESET;
    std::cout << "ScavTrap " << getName() << " attacks " << target
            << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << GREEN << "[GUARD_GATE] " << RESET;
    std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode." << std::endl;
}