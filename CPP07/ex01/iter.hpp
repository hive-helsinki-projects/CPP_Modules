/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:27:24 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/23 12:45:48 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int length, void (*func)(T const &))
{
    for (int i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

template <typename T>
void print(T const &x)
{
    std::cout << x << " ";
}

#endif