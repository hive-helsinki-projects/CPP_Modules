/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:19:49 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/11 12:26:32 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int main() {
    // Create ClapTrap objects
    ClapTrap clapTrap1("1");
    ClapTrap clapTrap2("2");

    // Set Attack Damage
    clapTrap1.setAttackDamage(5);
    clapTrap2.setAttackDamage(10);

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
    
    // 1 attacks 2
    std::string target = "ClapTrap 2";
    clapTrap1.attack(target);
    clapTrap2.takeDamage(5);
    clapTrap2.beRepaired(3);

    // 2 attacks 1
    std::string target1 = "ClapTrap 1";
    clapTrap2.attack(target1);
    clapTrap1.takeDamage(10);
    clapTrap1.beRepaired(5);

    // 1 attacks 2
    clapTrap1.attack(target);

    return 0;
}