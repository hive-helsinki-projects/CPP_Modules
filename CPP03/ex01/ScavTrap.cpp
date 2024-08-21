/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:33:38 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/21 11:50:00 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name) {
        hitPoints = 100;
        energyPoints = 50;
        attackDamage = 20;
        std::cout << GREEN << "ScavTrap " << name << " constructed." << std::endl << RESET;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {}
    
ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << GREEN << "ScavTrap " << name << " destructed." << std::endl << RESET; 
}

void ScavTrap::attack(const std::string& target){
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << GREEN << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl << RESET;
        --energyPoints;
    } else {
        std::cout << GREEN << "ScavTrap " << name << " cannot attack." << std::endl << RESET;
    }
}

void ScavTrap::guardGate() {
    std::cout << GREEN << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl << RESET;
}