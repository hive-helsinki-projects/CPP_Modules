/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:08:48 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/15 12:36:15 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon& weapon; // Reference to a Weapon
    public:
    HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {}
        void attack() const {
            std::cout << name << " attacks with their " << weapon.getType() << "\n";
        }
};

#endif