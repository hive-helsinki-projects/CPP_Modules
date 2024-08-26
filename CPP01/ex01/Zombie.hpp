/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:38:46 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/26 12:15:18 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

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
