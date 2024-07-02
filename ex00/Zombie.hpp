/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:47:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/07/02 14:03:23 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        Zombie(std::string name) : name(name) {} 
        void announce(void) {
            std::cout << name << ": BraiiiiiiinnnzzzZ..." << "\n";
        }
};