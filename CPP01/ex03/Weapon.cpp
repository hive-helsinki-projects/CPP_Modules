/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:27:05 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/26 09:45:48 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : type("default") {}

Weapon::Weapon(const std::string& type) : type(type) {};

Weapon::~Weapon() {}

void Weapon::setType(const std::string& newType) {
    type = newType;
}

const std::string& Weapon::getType() const {
    return type;
}
