/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:53:28 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/15 19:14:24 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceStringInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    // Open the input file
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return;
    }

    // Create the output file
    std::ofstream outputFile(filename + ".replace");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create the file " << filename << ".replace" << std::endl;
        return;
    }

    std::string line;
    size_t pos;

    while (std::getline(inputFile, line)) {
        // Replace all occurrences of s1 with s2
        while ((pos = line.find(s1)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
        }
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << "\n";
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2= argv[3];

    replaceStringInFile(filename, s1, s2);

    return 0;
}