/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:49:26 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/20 19:14:34 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Extract coordinates
Fixed Point::getX() const {
    return this->x;
}

Fixed Point::getY() const {
    return this->y;
}

// Calculate differences in y-coordinates
Fixed diffY(Point const &p1, Point const &p2) {
    return p1.getY() - p2.getY();
}

// Multiply differences by corresponding x-coordinates
Fixed multiplyDiffX(Fixed x, Fixed diffY) {
    return x * diffY;
}

// Sum the products
Fixed sumProducts(Fixed prod1, Fixed prod2, Fixed prod3) {
    return prod1 + prod2 + prod3;
}

// Calculate and return the area
Fixed calculateArea(Fixed sum) {
    return Fixed(0.5f) * sum.abs();
}

// Main area function
Fixed Point::area(Point const &p1, Point const &p2, Point const &p3) {
    // Extract coordinates
    Fixed x1 = p1.getX();
    Fixed y1 = p1.getY();
    Fixed x2 = p2.getX();
    Fixed y2 = p2.getY();
    Fixed x3 = p3.getX();
    Fixed y3 = p3.getY();

    // Calculate differences in y-coordinates
    Fixed diffY1 = diffY(p2, p3);
    Fixed diffY2 = diffY(p3, p1);
    Fixed diffY3 = diffY(p1, p2);

    // Multiply differences by corresponding x-coordinates
    Fixed prod1 = multiplyDiffX(x1, diffY1);
    Fixed prod2 = multiplyDiffX(x2, diffY2);
    Fixed prod3 = multiplyDiffX(x3, diffY3);

    // Sum the products
    Fixed sum = sumProducts(prod1, prod2, prod3);

    // Calculate and return the area
    return calculateArea(sum);
}

bool Point::bsp(Point const a, Point const b, Point const c, Point const point) {
    // Calculate the area of the main triangle abc
    Fixed areaABC = area(a, b, c);

    // Calculate the areas of the triangles formed with the point p
    Fixed areaPAB = area(point, a, b);
    Fixed areaPBC = area(point, b, c);
    Fixed areaPCA = area(point, c, a);

    // Check if the point is on the edge or a vertex
    if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0)) {
        return false; // Point is on the edge or a vertex
    }

    // Check if the sum of the areas of pab, pbc, and pca equals the area of abc
    return (areaPAB + areaPBC + areaPCA) == areaABC;
}
