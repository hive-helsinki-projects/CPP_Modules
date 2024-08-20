/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:19:49 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/20 20:20:13 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int main() {
    // Create ClapTrap objects
    ClapTrap claptrap1("ClapTrap1");
    ClapTrap claptrap2("ClapTrap2");

    // Test attack function
    claptrap1.attack("ClapTrap2");

    // Test takeDamage function
    claptrap2.takeDamage(5);

    // Test beRepaired function
    claptrap2.beRepaired(3);

    // Test copy constructor
    ClapTrap claptrap3(claptrap1);
    claptrap3.attack("ClapTrap2");

    // Test assignment operator
    ClapTrap claptrap4 = claptrap2;
    claptrap4.takeDamage(2);

    return 0;
}