/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:07:51 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/10 16:45:05 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DADSHELL_H
#define DADSHELL_H

#include <libft.h>
#include <ft_printf.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#define MAX_BUILTINS 3
#define STD_ENV 1



void 	dad_loop(int fd);
void	throw_err(char *msg);
int		dadsh_launch(char **args);
int		dadsh_exec(char **args);
void	put_help_msg(void);
void	init_shell(int fd, char **env);

/*
** Helper
*/
void	echo_out(char **args, int pos);

/* 
** Built-Ins
*/
int		dadsh_cd(char **args);
int		dadsh_echo(char **args);
int		dadsh_env(char **args);
int		dadsh_setenv(char **args);
int		dadsh_unsetenv(char **args);
int		dadsh_help(char **args);
int		dadsh_exit(char **args);

#endif 