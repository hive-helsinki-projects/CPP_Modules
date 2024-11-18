/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:35:30 by lkilpela          #+#    #+#             */
/*   Updated: 2024/11/18 23:35:42 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <stack> // stack
#include <stdexcept> // runtime_error
#include <cctype> // isdigit

int RPN::evaluate(const char* expression) {
    std::stack<int> stack;
    const char* p = expression;

    while (*p) {
        if (std::isspace(*p)) {
            p++;
        } else if (std::isdigit(*p)) {
            stack.push(std::strtol(p, const_cast<char**>(&p), 10));
        } else {
            if (stack.size() < 2) {
                throw std::runtime_error("Error: not enough operands");
            }

            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            switch (*p) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    if (b == 0) {
                        throw std::runtime_error("Error: division by zero");
                    }
                    stack.push(a / b);
                    break;
                default:
                    throw std::runtime_error("Error: invalid operator");
            }

            p++;
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Error: too many operands");
    }

    return stack.top();
}