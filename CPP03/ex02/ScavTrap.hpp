/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:27:25 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/11 13:52:03 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

# define GREEN "\033[0;32m"
# define BLUE "\033[34m"
# define RED "\033[0;31m"
# define RESET "\033[0m"

class ScavTrap: public ClapTrap {
public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap &other);
    ~ScavTrap();

    void attack(const std::string& target) override;
    void guardGate();
};

#endif