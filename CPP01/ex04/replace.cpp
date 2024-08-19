/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:42:01 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/19 12:05:43 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

static std::string replaceAll(const std::string& str, const std::string s1, const std::string s2) {
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

void    replaceInfile(const std::string& filename, const std::string& s1, const std::string& s2) {
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

    if (!std::getline(inputFile, line)) {
    std::cerr << "Error: The file " << filename << " is empty or could not be read" << std::endl;
    return;
    }

    // Process the first line
    outputFile << replaceAll(line, s1, s2) << "\n";
    
    while (std::getline(inputFile, line)) {
        outputFile << replaceAll(line, s1, s2) << "\n";
        if (outputFile.bad()) {
            std::cerr << "Error: Failed to write from the file " << filename << ".new" << std::endl;
            return;
        }
    }
}

