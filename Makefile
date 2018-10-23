# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/18 16:38:40 by egoodale          #+#    #+#              #
#    Updated: 2018/10/23 16:00:35 by egoodale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
INCLUDE = ./include/dadshell.h
SRC_DIR = ./src/
SRC = 	builtins.c echo.c env_helper.c\
		exec.c helper.c input.c\
		main.c setenv.c unsetenv.c\

OBJ_DIR = ./obj/
OBJ = $(patsubst %.c, %.o, $(SRC))
CFLAGS = -Wall -Werror -Wextra -g 
LIBFT_A = libft/libft.a

all: $(NAME)


$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT_A)
	@CC $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT_A)
$(OBJ): %.o: $(SRC_DIR)%.c
	@CC -c $(CFLAGS) -I $(SRC_DIR) -I $(INCLUDE) $< -o $@
$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all 