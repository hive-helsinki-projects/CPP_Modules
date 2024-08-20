/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:47:36 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/20 19:48:08 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string& str, const std::string s1, const std::string s2);
void    replaceInfile(const std::string& filename, const std::string& s1, const std::string& s2);

#endif