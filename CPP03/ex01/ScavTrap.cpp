/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:33:38 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/21 11:45:03 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name) {
        hitPoints = 100;
        energyPoints = 50;
        attackDamage = 20;
        std::cout << "ScavTrap " << name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {}
    
ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " destructed." << std::endl;
}

void ScavTrap::attack(const std::string& target){
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        --energyPoints;
    } else {
        std::cout << "ScavTrap " << name << " cannot attack." << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}