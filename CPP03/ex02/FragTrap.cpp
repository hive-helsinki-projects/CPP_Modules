/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:18:02 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/11 14:38:15 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap " << getName() << " created by default constructor." << std::endl;
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name) {
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout  << "FragTrap " << name << " created by parameterized constructor." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap " << getName() << " created by copy constructor." << std::endl;
}
    
FragTrap& FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << getName() << " destroyed." << std::endl; 
}

void FragTrap::highFivesGuys(void) {
    std::cout << BLUE << "[HIGH_FIVES] " << RESET;
    std::cout << "FragTrap " << getName() << " requests high fives!" << std::endl;
}
