/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:42:19 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/24 12:16:13 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

// Template for the container type.
template <typename T> 

// Function that searches for a value in a container.
int easyfind(T& container, int value) {
    // Initializes begin to the iterator pointing to the start of the container.
    auto begin = container.begin();
    
    // Initializes end to the iterator pointing to the end of the container
    auto end = container.end();
    
    // Uses std::find to search for the value between begin and end,
    // and initializes it to the result.
    auto it = std::find(begin, end, value);

    // If the value is found, return the value.
    if (it != end) {
        return *it;
    } else {
        throw std::runtime_error("Value not found in container");
    }
}

#endif