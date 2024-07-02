/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:47:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/07/02 14:36:11 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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