/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:42:01 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/18 09:27:00 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

std::string replaceAll(const std::string& str, const std::string& s1, const std::string& s2) {
    std::string result;
    size_t pos = 0; // position of found subtring
    size_t prevPos = 0; // position of the previous substring

    pos = str.find(s1, prevPos);
    while(pos != std::string::npos) {
        result.append(str, prevPos, pos - prevPos);
        result.append(s2);
        prevPos = pos + s1.length();
    }
    result.append(str, prevPos, std::string::npos);
    return result;
}