/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:47:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/18 18:34:13 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        Zombie(std::string name) : name(name) {} 

        ~Zombie() {
            std::cout << name << " is destroyed." << "\n";
        }
        void announce(void) {
            std::cout << name << ": BraiiiiiiinnnzzzZ..." << "\n";
        }
};

Zombie* newZombie( std::string name);

void randomChump( std::string name );

#endif