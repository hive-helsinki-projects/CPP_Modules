# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 10:48:55 by lkilpela          #+#    #+#              #
#    Updated: 2024/10/18 11:55:12 by lkilpela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	convert

CC			=	c++
CCFLAGS		=	-Wall -Wextra -Werror -std=c++11
SRCS		=	main.cpp ScalarConverter.cpp
OBJS		=	$(SRCS:%.cpp=%.o)

all: $(NAME)

%.o : %.cpp
	@$(CC) $(CCFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled: $< $(RESET)"

$(NAME): $(OBJS)
	@echo "--------------------------------------------"
	@$(CC) $(OBJS) -o $(NAME)
	@echo "[$(NAME)] $(BLUE)Built target $(NAME)$(RESET)"
	@echo "--------------------------------------------"

clean:
	@rm -rf $(OBJS)
	@echo "[$(NAME)] Object files cleaned."

fclean: clean
	@rm -rf $(NAME)
	@echo "[$(NAME)] Everything deleted."

re: fclean all
	@echo "[$(NAME)] Everything rebuilt."

test: $(NAME)
	@echo "$(BLUE)Running tests... $(RESET)"
	@echo "--------------------------------------------"
	@echo "$(GREEN)Test: 2147483648 (int overflow) $(RESET)"
	@./$(NAME) 2147483648
	@echo "$(GREEN)Test: -2147483649 (int underflow)$(RESET)"
	@./$(NAME) -2147483649
	@echo "--------------------------------------------"
	@echo "$(GREEN)Test: 3.4e38 (float overflow)$(RESET)"
	@./$(NAME) 3.4e38
	@echo "$(GREEN)Test: -3.4e38 (float underflow)$(RESET)"
	@./$(NAME) -3.4e38
	@echo "$(GREEN)Test: 1.2e-38 (float underflow)$(RESET)"
	@./$(NAME) 1.2e-38
	@echo "$(GREEN)Test: -1.2e-38 (float underflow)$(RESET)"
	@./$(NAME) -1.2e-38
	@echo "--------------------------------------------"
	@echo "$(GREEN)Test: 1e308 (double overflow)$(RESET)"
	@./$(NAME) 1e308
	@echo "$(GREEN)Test: -1e308 (double underflow)$(RESET)"
	@./$(NAME) -1e308
	@echo "$(GREEN)Test: 1e-308 (double underflow)$(RESET)"
	@./$(NAME) 1e-308
	@echo "$(GREEN)Test: -1e-308 (double underflow)$(RESET)"
	@./$(NAME) -1e-308
	@echo "--------------------------------------------"

.PHONY: all clean fclean re test

GREEN = \033[0;32m
RESET = \033[0m
BLUE = \033[34m