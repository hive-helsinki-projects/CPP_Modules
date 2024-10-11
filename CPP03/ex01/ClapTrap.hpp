/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:00:58 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/11 10:40:43 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define GREEN "\033[0;32m"
# define BLUE "\033[34m"
# define RED "\033[0;31m"
# define RESET "\033[0m"

class ClapTrap {
private:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    // Constructors and Destructors
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();
    
    // Getters and Setters
    void setName(const std::string& n);
    std::string getName() const;
    void setHitPoints(unsigned int hp);
    unsigned int getHitPoints() const;
    void setEnergyPoints(unsigned int ep);
    unsigned int getEnergyPoints() const;
    void setAttackDamage(unsigned int ad);
    unsigned int getAttackDamage() const;
    
    // Member functions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif