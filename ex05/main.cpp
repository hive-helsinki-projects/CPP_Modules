/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:59:52 by lkilpela          #+#    #+#             */
/*   Updated: 2024/08/18 19:01:10 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "DEBUG level:" << std::endl;
    harl.complain("debug");

    std::cout << "\nINFO level:" << std::endl;
    harl.complain("info");

    std::cout << "\nWARNING level:" << std::endl;
    harl.complain("warning");

    std::cout << "\nERROR level:" << std::endl;
    harl.complain("error");

    std::cout << "\nInvalid level:" << std::endl;
    harl.complain("invalid");

    return 0;
}