/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:19:49 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/21 09:24:55 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int main() {
    // Create ClapTrap objects
    ClapTrap claptrap1("1");
    ClapTrap claptrap2("2");

    // Test attack function
    claptrap1.attack("2");

    // Test takeDamage function
    claptrap2.takeDamage(5);

    // Test beRepaired function
    claptrap2.beRepaired(3);

    // Test copy constructor
    ClapTrap claptrap3(claptrap1);
    
    claptrap3.attack("2");

    claptrap2.attack("1");

    claptrap1.takeDamage(10);

    // Test beRepaired function
    claptrap1.beRepaired(5);

    claptrap1.attack("2");

    return 0;
}