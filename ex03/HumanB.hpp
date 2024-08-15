/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:08:48 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/15 12:21:15 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB {
    private:
        std::string name;
        Weapon* weapon; // Pointer to a Weapon
    public:
    HumanB(const std::string& name, Weapon& weapon) : name(name), weapon(nullptr) {}
        void setWeapon(Weapon& weapon) {
            this->weapon = &weapon;
        }
        void attack() const {
            if (weapon) {
                std::cout << name << " attacks with their " << weapon->getType() << "\n";
            } else {
                std::cout << name << " has no weapon to attack with!" << "\n";
            }
        }
};