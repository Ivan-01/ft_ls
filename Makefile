# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ititkov <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/20 09:00:04 by ititkov           #+#    #+#              #
#    Updated: 2019/03/27 12:42:18 by ititkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -I includes
SRC = ./src/*
UTILS = ./utils/*
NAME = libft_ls.a
EXEC = ft_ls
LIBFT = libft/libft.a
GCCW = gcc -Wall -Wextra -Werror

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m

$(NAME):
	@echo "$(GREEN)Making object files for $(NAME)$(RESET)"
	@$(GCCW) -c $(SRC) $(UTILS) $(INCLUDES)
	@echo "$(GREEN)Compiling $(NAME)$(RESET)"
	@make -C libft
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
	@echo "$(GREEN)Compiling an executable file $(EXEc)$(RESET)"
	@$(GCCW) $(NAME) $(LIBFT) $(INCLUDES) main.c -o $(EXEC)
	@echo "$(BLUE)$(NAME): Completed $(RESET)"

all: $(NAME)

clean:
	@echo "$(RED)Deleting object files for $(NAME)$(RESET)"
	@/bin/rm -f *.o
	@make -C libft clean
	@echo "$(BLUE)cleaning: Complited$(RESSET)"

fclean: clean
	@echo "$(RED)Deleting $(NAME)$(RESE)"
	@/bin/rm -f $(NAME)
	@echo "$(RED)Deleting $(EXEC)$(RESET)"
	@/bin/rm -f $(EXEC)
	@make -C libft fclean
	@echo "$(BLUE)fclean: Completed$(RESET)"

re: fclean all
