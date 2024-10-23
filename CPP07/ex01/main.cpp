/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:32:38 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/23 12:43:54 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

int main()
{
    // Test with int array
    int array[] = {1, 2, 3, 4, 5};
    iter(array, 5, print);
    std::cout << std::endl;

    // Test with char array
    char array2[] = {'a', 'b', 'c', 'd', 'e'};
    iter(array2, 5, print);
    std::cout << std::endl;
    
    // Test with string array
    std::string array3[] = {"one", "two", "three", "four", "five"};
    iter(array3, 5, print);
    std::cout << std::endl;
    
    // Test with double array
    double array4[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    iter(array4, 5, print);
    std::cout << std::endl;
    
    return 0;
}

