/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:19:49 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/11 14:22:23 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

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
    // FragTrap objects
    FragTrap FragTrap1("1");
    FragTrap FragTrap2("2");
    
    // Set Attack Damage
    FragTrap1.setAttackDamage(5);
    FragTrap2.setAttackDamage(10);
    
    print_obj(FragTrap1, FragTrap2);

    // 1 attacks 2
    std::string target = "FragTrap 2";
    FragTrap1.attack(target);
    FragTrap1.guardGate();

    // 2 attacks 1
    std::string target1 = "FragTrap 1";
    FragTrap2.attack(target1);
    FragTrap2.guardGate();
    
    return 0;
}