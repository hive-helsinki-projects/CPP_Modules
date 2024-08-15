/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:37:17 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/15 11:35:09 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    Zombie horde(name);
    if (N <=0) return nullptr;
    // Zombie* horde = new Zombie(name);
    for (int i = 0; i < N; i++) {
        horde[i] = Zombie(name);
    }
    return (horde);
}