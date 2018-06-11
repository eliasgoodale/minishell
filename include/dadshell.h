/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:07:51 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/11 13:22:46 by egoodale         ###   ########.fr       */
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

char **g_envv;


void 	dad_loop(int fd);
int		dadsh_launch(char **args);
int		dadsh_exec(char **args);
void	put_help_msg(void);


/*
** Process Execution
*/
int		dadsh_exec(char **args);

/*
** Helper
*/
void	ft_freestrarr(char **arr);
int		arr_len(char **envv);
void	print_env(void);
void	init_envv(char **env);
char	*get_envv(char *var);
int		find_envv(char *var);
void	throw_err(char *msg);

/*
** Signal Handling
*/
void	dad_signal(int sig);
void	dad_psignal(int sig);
/* 
** Built-Ins
*/
int		dadsh_cd(char **args);
int		dadsh_echo(char **args);
void	echo_out(char **args, int pos);
int		dadsh_env(char **args);
int		dadsh_setenv(char **args);
int		dadsh_unsetenv(char **args);
int		dadsh_help(char **args);
int		dadsh_exit(char **args);

#endif 