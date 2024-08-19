/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:50:01 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/15 11:57:55 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    // Declare and initialize a string variable
    std::string str = "HI THIS IS BRAIN";
    
    // Declare a pointer to the string
    std::string* stringPTR = &str;

    // Declare a reference to the string
    std::string& stringREF = str;

    std::cout << "Memory address of the string variable: " << &str << "\n";
    std::cout << "Memory address held by stringPTR: " << stringPTR << "\n";
    std::cout << "Memory address held by stringREF: " << &stringREF << "\n";

    std::cout << "Value of the string variable: " << str << "\n";
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << "\n";
    std::cout << "Value pointed to by stringREF: " << stringREF << "\n";

    return 0;
}
