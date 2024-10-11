/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:05:43 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/11 09:50:22 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* CONSTRUCTORS AND DESTRUCTORS */
ClapTrap::ClapTrap() :  name("Default"),
                        hitPoints(10),
                        energyPoints(10),
                        attackDamage(0)
{
    std::cout << "ClapTrap " << name << " created by default constructor." << std::endl;
}

// Parameterized Constructor
ClapTrap::ClapTrap(const std::string& name) :   name(name),
                                                hitPoints(10),
                                                energyPoints(10),
                                                attackDamage(0)
{
    std::cout << "ClapTrap " << name << " created." << std::endl;
}

// 
ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name),
                                            hitPoints(other.hitPoints),
                                            energyPoints(other.energyPoints),
                                            attackDamage(other.attackDamage)
{
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

/* GETTERS AND SETTERS */

void ClapTrap::setName(const std::string& n) {
    name = n;
}

std::string ClapTrap::getName() const {
    return name;
}

void ClapTrap::setHitPoints(unsigned int hp) {
    hitPoints = hp;
}

unsigned int ClapTrap::getHitPoints() const {
    return hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int ep) {
    energyPoints = ep;
}

unsigned int ClapTrap::getEnergyPoints() const {
    return energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int ad) {
    attackDamage = ad;
}

unsigned int ClapTrap::getAttackDamage() const {
    return attackDamage;
}

/* MEMBER FUNCTIONS */

void ClapTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        --energyPoints;
    } else {
        std::cout << "ClapTrap " << name << " cannot attack." << std::endl;
    }    
}
void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints > 0) {
        hitPoints = (amount >= hitPoints) ? 0 : (hitPoints - amount);
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining hit points: " << hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " is already destroyed." << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        hitPoints += amount;
        --energyPoints;
        std::cout << "ClapTrap " << name << " is repaired by " << amount << " points! Current hit points: " << hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " cannot be repaired." << std::endl;
    }
}