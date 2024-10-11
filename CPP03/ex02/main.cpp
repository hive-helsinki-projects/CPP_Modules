/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:19:49 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/11 14:53:23 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void print_clap(ClapTrap& clapTrap1, ClapTrap& clapTrap2)
{
    // Print ClapTrap objects' infos
    std::cout << "--------------------------------" << std::endl;
    std::cout << BLUE << "ScavTrap's infos: " << std::endl << RESET;
    std::cout << "1. Name: " << clapTrap1.getName() << std::endl;
    std::cout << "2. Health: " << clapTrap1.getHitPoints() << std::endl;
    std::cout << "3. Energy points: " << clapTrap1.getEnergyPoints() << std::endl;
    std::cout << "4. Attack damage: " << clapTrap1.getAttackDamage() << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "1. Name: " << clapTrap2.getName() << std::endl;
    std::cout << "2. Health: " << clapTrap2.getHitPoints() << std::endl;
    std::cout << "3. Energy points: " << clapTrap2.getEnergyPoints() << std::endl;
    std::cout << "4. Attack damage: " << clapTrap2.getAttackDamage() << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

void print_scav(ScavTrap& scavTrap1, ScavTrap& scavTrap2)
{
    // Print ScavTrap objects' infos
    std::cout << "--------------------------------" << std::endl;
    std::cout << BLUE << "ScavTrap's infos: " << std::endl << RESET;
    std::cout << "1. Name: " << scavTrap1.getName() << std::endl;
    std::cout << "2. Health: " << scavTrap1.getHitPoints() << std::endl;
    std::cout << "3. Energy points: " << scavTrap1.getEnergyPoints() << std::endl;
    std::cout << "4. Attack damage: " << scavTrap1.getAttackDamage() << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "1. Name: " << scavTrap2.getName() << std::endl;
    std::cout << "2. Health: " << scavTrap2.getHitPoints() << std::endl;
    std::cout << "3. Energy points: " << scavTrap2.getEnergyPoints() << std::endl;
    std::cout << "4. Attack damage: " << scavTrap2.getAttackDamage() << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

void print_frag(FragTrap& fragTrap1, FragTrap& fragTrap2)
{
    // Print FragTrap objects' infos
    std::cout << "--------------------------------" << std::endl;
    std::cout << BLUE << "FragTrap's infos: " << std::endl << RESET;
    std::cout << "1. Name: " << fragTrap1.getName() << std::endl;
    std::cout << "2. Health: " << fragTrap1.getHitPoints() << std::endl;
    std::cout << "3. Energy points: " << fragTrap1.getEnergyPoints() << std::endl;
    std::cout << "4. Attack damage: " << fragTrap1.getAttackDamage() << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "1. Name: " << fragTrap2.getName() << std::endl;
    std::cout << "2. Health: " << fragTrap2.getHitPoints() << std::endl;
    std::cout << "3. Energy points: " << fragTrap2.getEnergyPoints() << std::endl;
    std::cout << "4. Attack damage: " << fragTrap2.getAttackDamage() << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

int main() {
    // ClapTrap objects
    ClapTrap clapTrap1("C1");
    ClapTrap clapTrap2("C2");
    
    // ScavTrap objects
    ScavTrap scavTrap1("S1");
    ScavTrap scavTrap2("S2");
    
    // FragTrap objects
    FragTrap FragTrap1("F1");
    FragTrap FragTrap2("F2");
    
    print_clap(clapTrap1, clapTrap2);
    print_scav(scavTrap1, scavTrap2);
    print_frag(FragTrap1, FragTrap2);

    // F1 attacks F2
    FragTrap1.attack("F2");
    FragTrap2.takeDamage(FragTrap1.getAttackDamage()); // The derived class DON'T inherit takeDamage for base class
    // F2 attacks F1
    FragTrap2.attack("F1");
    
    FragTrap1.highFivesGuys();
    FragTrap2.highFivesGuys();
    
    return 0;
}