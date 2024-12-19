/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:35:54 by lkilpela          #+#    #+#             */
/*   Updated: 2024/12/19 13:49:13 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string> // std::string
#include <stack> // std::stack

class RPN {
private:
    std::string expression;
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    
    static int evaluate(const std::string& expression);
};
