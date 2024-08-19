/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:59:52 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/18 19:13:51 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "DEBUG level:" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\nINFO level:" << std::endl;
    harl.complain("INFO");

    std::cout << "\nWARNING level:" << std::endl;
    harl.complain("WARNING");

    std::cout << "\nERROR level:" << std::endl;
    harl.complain("ERROR");

    std::cout << "\nINVALID level:" << std::endl;
    harl.complain("INVALID");

    return 0;
}