/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:44:53 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/26 09:35:47 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int N = 5;
    std::string name = "ZombieHorde";
    Zombie* horde = zombieHorde(N, name);
    if (horde) {
        for (int i = 0; i < N; ++i) {
            horde[i].announce();
    }
    delete[] horde;
    } else {
        std::cerr << "Failed to create zombie horde" << std::endl;
    }

    return 0;
}