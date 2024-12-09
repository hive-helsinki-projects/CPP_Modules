/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:35:46 by lkilpela          #+#    #+#             */
/*   Updated: 2024/12/09 17:28:02 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>
# include <iterator>

# define YELLOW "\033[33m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Type definnition for iterator
    using iterator = typename std::stack<T>::container_type::iterator;
    using const_iterator = typename std::stack<T>::container_type::const_iterator;
    
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack& other) : std::stack<T>(other) {}
    MutantStack &operator=(const MutantStack& other) {
        std::stack<T>::operator=(other);
        return *this;
    }
    ~MutantStack() {}
  
    // Iterator methods
    iterator begin() {
        return std::stack<T>::c.begin();
    }
    iterator end() {
        return std::stack<T>::c.end();
    }
    const_iterator begin() const {
        return std::stack<T>::c.begin();
    }
    const_iterator end() const {
        return std::stack<T>::c.end();
    }
};

#endif