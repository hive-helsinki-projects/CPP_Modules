/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 05:37:18 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/20 12:56:04 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);
    Point inside(1, 1);
    Point outside(10, 10);
    Point onEdge(0, 5);
    Point vertex(0, 0);

    std::cout << "Inside: " << bsp(a, b, c, inside) << std::endl; // Expected: 1 (true)
    std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl; // Expected: 0 (false)
    std::cout << "On Edge: " << bsp(a, b, c, onEdge) << std::endl; // Expected: 0 (false)
    std::cout << "Vertex: " << bsp(a, b, c, vertex) << std::endl; // Expected: 0 (false)

    return 0;
}