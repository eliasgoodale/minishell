/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:07:51 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/10 13:56:36 by egoodale         ###   ########.fr       */
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

typedef struct	s_alias
{
	char *alias;
	char *command;
}				t_alias;

t_alias 	g_alias_tab[] = {
	{"ls" : "~/bin/ft_ls"}
}

char **ENV;

typedef enum process_{COMPLETED, STOPPED, STATUS}

typedef struct		s_process
{
	bool shell_is_interactive;
	bool completed;
	bool stopped;
    struct s_process *next;
    char **args
    pid_t pid;
}					t_process;

typedef struct s_job
{
    struct s_job *next;
    char *command;
    t_process *first_process;
    pid_t pgid;
    char notified;
    struct termios tmodes;
    int stdin; 
	int stdout;
	int	stderr;
}               t_job;


void 	dad_loop(int fd);
void	throw_err(char *msg);
int		dadsh_launch(char **args);
int		dadsh_exec(char **args);
void	put_help_msg(void);
int		dadsh_cd(char **args);
int		dadsh_help(char **args);
int		dadsh_exit(char **args);
void	init_shell(int fd, char **env);

#endif 