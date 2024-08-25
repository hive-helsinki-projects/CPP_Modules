/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:38:46 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/20 19:40:37 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include <iostream>

class Zombie {
private:
    std::string name;
public:
    Zombie(); // Default constructor
    Zombie(std::string name); // Initializer List 
    ~Zombie();
    void announce(void);
    void setName(std::string n);
};

Zombie* zombieHorde(int N, std::string name);

#endif
