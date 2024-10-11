/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:19:49 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/11 14:10:12 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void print_obj(ClapTrap& clapTrap1, ClapTrap& clapTrap2)
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

int main() {
    // ScavTrap objects
    ScavTrap scavTrap1("1");
    ScavTrap scavTrap2("2");
    
    // Set Attack Damage
    scavTrap1.setAttackDamage(5);
    scavTrap2.setAttackDamage(10);
    
    print_obj(scavTrap1, scavTrap2);

    // 1 attacks 2
    std::string target = "ScavTrap 2";
    scavTrap1.attack(target);
    scavTrap1.guardGate();

    // 2 attacks 1
    std::string target1 = "ScavTrap 1";
    scavTrap2.attack(target1);
    scavTrap2.guardGate();
    
    return 0;
}
