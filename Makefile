# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/09 15:40:12 by egoodale          #+#    #+#              #
#    Updated: 2018/06/09 19:43:15 by egoodale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dadshell
HDR = include/dadshell.h
SRC_DIR = ./src/
OBJ_DIR = ./obj/
SRC = main.c dadsh_exec.c dadsh_cd.c dad_echo.c dad_unsetenv.c dad_setenv.c dad_helper.c
OBJ = $(patsubst %.c, %.o, $(SRC))
CFLAGS = -g
LIBFT_A = libs/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	@CC $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT_A)
$(OBJ): %.o: $(SRC_DIR)%.c
	@CC -c $(CFLAGS) -I $(SRC_DIR) -I $(HDR) $< -o $@
$(LIBFT_A):
	@cd libft && make
clean:
	rm $(OBJ)
fclean: clean
	rm $(NAME)
re: fclean all