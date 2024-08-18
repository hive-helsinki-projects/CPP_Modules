/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:42:01 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/18 18:18:46 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

static std::string replaceAll(const std::string& str, const std::string& s1, const std::string& s2) {
    std::string result;
    size_t pos = 0; // position of found subtring
    size_t prevPos = 0; // position of the previous substring

    while((pos = str.find(s1, prevPos)) != std::string::npos) {
        result.append(str, prevPos, pos - prevPos);
        result.append(s2);
        prevPos = pos + s1.length();
    }
    result.append(str, prevPos, std::string::npos);
    return result;
}

void    replaceStringInfile(const std::string& filename, const std::string s1, const std::string s2) {
    std::ifstream inputFile(filename);
    std::ofstream outputFile(filename + ".new");
    std::string line;
    
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return ;
    }
    if (!outputFile.is_open()) {
       std::cerr << "Error: Could not create the file " << filename << ".new" << std::endl;
        return ;
    }

    while (std::getline(inputFile, line)) {
        outputFile << replaceAll(line, s1, s2) << "\n";
    }

    inputFile.close();
    outputFile.close();
}