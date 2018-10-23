# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/15 12:27:58 by egoodale          #+#    #+#              #
#    Updated: 2018/07/15 12:33:59 by egoodale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_suite
MAIN_DRIVER = main.c
LIBFT_A = ../libft.a
HDR = ~/HDR/
CFLAGS = -Wall -Werror -Wextra -g
all: $(NAME)

$(NAME): $(MAIN_DRIVER) $(LIBFT_A)
	gcc $(CFLAGS) -I $(HDR) $(MAIN_DRIVER) -o $(NAME) $(LIBFT_A)
