/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:03:50 by lkilpela          #+#    #+#             */
/*   Updated: 2024/10/17 15:36:28 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm* rrf;

    rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (rrf) {
        std::cout << *rrf << std::endl;
        delete rrf;
    }

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        std::cout << *rrf << std::endl;
        delete rrf;
    }
    
    rrf = someRandomIntern.makeForm("presidential pardon", "Alice");
    if (rrf) {
        std::cout << *rrf << std::endl;
        delete rrf;
    }

    rrf = someRandomIntern.makeForm("unknown", "Bob");
    if (rrf) {
        std::cout << *rrf << std::endl;
        delete rrf;
    }

    return 0;
}
