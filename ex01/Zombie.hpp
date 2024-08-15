/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:38:46 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/15 11:29:38 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        //Zombie() : name("default") {} // Default constructor
        Zombie(std::string name) : name(name) {} // Initializer List 

        ~Zombie() {
            std::cout << name << " is destroyed." << "\n";
        }
        void announce(void) {
            std::cout << name << ": BraiiiiiiinnnzzzZ..." << "\n";
        }
};

Zombie* zombieHorde( int N, std::string name );