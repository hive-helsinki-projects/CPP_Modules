/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:49:26 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/20 12:55:35 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include "Point.hpp"

// Extract coordinates
Fixed getX(Point const &p) {
    return p.getX();
}

Fixed getY(Point const &p) {
    return p.getY();
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
Fixed area(Point const &p1, Point const &p2, Point const &p3) {
    // Extract coordinates
    Fixed x1 = getX(p1);
    Fixed y1 = getY(p1);
    Fixed x2 = getX(p2);
    Fixed y2 = getY(p2);
    Fixed x3 = getX(p3);
    Fixed y3 = getY(p3);

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
3
    // Calculate and return the area
    return calculateArea(sum);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
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
