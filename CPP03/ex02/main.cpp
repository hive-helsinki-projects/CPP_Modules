/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:19:49 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/21 12:41:34 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << BLUE << "\nCreating ClapTrap objects:" << std::endl << RESET;
    ClapTrap claptrap1("ClapTrap1");
    ClapTrap claptrap2("ClapTrap2");

    claptrap2.beRepaired(3);

    // Test copy constructor
    ClapTrap claptrap3(claptrap1);
    
    claptrap3.attack("2");

    claptrap2.attack("1");

    claptrap1.takeDamage(10);

    // Test beRepaired function
    claptrap1.beRepaired(5);

    claptrap1.attack("2");

    std::cout << "----------------------------------------" << std::endl;
    std::cout << BLUE  << "\nCreating ScavTrap objects:" << std::endl << RESET;
    ScavTrap scavtrap1("ScavTrap1");
    scavtrap1.attack("target1");
    scavtrap1.guardGate();

    ScavTrap scavtrap2(scavtrap1);
    scavtrap2.attack("target2");

    std::cout << "----------------------------------------" << std::endl;
    std::cout << BLUE << "\nCreating FragTrap objects:" << std::endl << RESET;
    FragTrap fragtrap1("FragTrap1");
    fragtrap1.attack("target1");
    fragtrap1.highFivesGuys();

    FragTrap fragtrap2(fragtrap1);
    fragtrap2.attack("target2");
    
    std::cout << "----------------------------------------" << std::endl;
    std::cout << BLUE << "\nEnd of main, destructors will be called:" << std::endl << RESET;
    return 0;
}