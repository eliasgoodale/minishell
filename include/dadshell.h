/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:07:51 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/18 15:55:22 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DADSHELL_H
#define DADSHELL_H

#include <libft.h>
#include <ft_printf.h>
#include <get_next_line.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <dirent.h>

enum	e_dadsh_constants
{
	STD_ENVV = 3,
	BUILTINS = 7,
	LINE_IN_CAP = 50,
	DAD_PATH_MAX = 1024

};

size_t			g_exec_args;
const char		*g_quotes = "\'\"`";

extern	t_vector *g_envv;

typedef struct dirent	t_dirent;

void 	dad_loop(int fd);
void	put_help_msg(void);
int		dad_init_envv(char **custom);
/*
** Process Execution
*/
int		dad_exec(t_vector *line_in);
int		delta_exec(char *path, char **args);
int		dad_launch(char **args);
static  int dad_run(char *path, char **args);

/*
** Helper
*/
void	ft_freestrarr(char **arr);
int		arr_len(char **arr);
int 	print_env(void);
void	init_envv(char **env);
int		find_envv(char *var);
char    **realloc_envv(int new_size);
char 	*ft_prepend_str(char *prefix, char *suffix);
char    *get_envv_val(char *envv_str);
char    *split_envv_key(char *envv_str);
int		inside_cwd(char *path);
char 	*ft_prepend_str(char *prefix, char *suffix);
/*
** Signal Handling
*/
void	dad_signal(int sig);
void	dad_psignal(int sig);

/* 
** Built-Ins
*/
int		dad_cd(char **args);
int		dad_echo(char **args);
void	echo_out(char **args);
int		dad_env(char **args);
int		dad_setenv(char **args);
int		dad_unsetenv(char **args);
int		dad_help(char **args);
int		dad_exit(char **args);

/*
**	Input Scrubbing
*/
char		**dad_input(t_vector *line_in, char *opnq, char *clsq, int fd);
void		quote_message(char quote);
char		**normalize_input(char *input);
void         prompt_user(t_vector *v, char *opnq, char *clsq, int fd);

typedef	int		(*t_dadfunc)(char **args);
static struct	s_builtin
{
	char		*name;
	size_t		tokenlen;
	t_dadfunc	dadfunc;
}
t_builtin[BUILTINS] = {
	{"cd", 2, &dad_cd},
	{"echo", 4, &dad_echo},
	{"env", 3, &dad_env},
	{"setenv", 6, &dad_setenv},
	{"unsetenv", 8, &dad_unsetenv},
	{"help", 4, &dad_help},
	{"exit", 4, &dad_exit}
};







#endif 