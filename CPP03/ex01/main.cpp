/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:19:49 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/11 14:30:10 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

void print_clap(ClapTrap& clapTrap1, ClapTrap& clapTrap2)
{
    // Print ClapTrap objects' infos
    std::cout << "--------------------------------" << std::endl;
    std::cout << BLUE << "ClapTrap's infos: " << std::endl << RESET;
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

int main() {
    // ClapTrap objects
    ClapTrap clapTrap1("C1");
    ClapTrap clapTrap2("C2");
    
    // ScavTrap objects
    ScavTrap scavTrap1("S1");
    ScavTrap scavTrap2("S2");
    
    print_clap(clapTrap1, clapTrap2);
    print_scav(scavTrap1, scavTrap2);

    // S1 attacks S2
    std::string target = "ScavTrap 2";
    scavTrap1.attack(target);
    scavTrap1.guardGate();

    // S2 attacks S1
    std::string target1 = "ScavTrap 1";
    scavTrap2.attack(target1);
    scavTrap2.guardGate();
    
    return 0;
}
