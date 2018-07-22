/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:17:14 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/21 09:29:16 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

char	*g_builtin_str[MAX_BUILTINS + 1] = {
	"cd",
	"echo",
	"env",
	"setenv",
	"unsetenv",
	"help",
	"exit"
};

t_builtin g_dadsh_cmds[MAX_BUILTINS] = {
	&dadsh_cd,
	&dadsh_echo,
	&dadsh_env,
	&dadsh_setenv,
	&dadsh_unsetenv,
	&dadsh_help,
	&dadsh_exit
};

int		main(int ac, char **envv)
{
	char *ttyfile = "/dev/ttys001";
	int fd;
	t_vector	line_in;

	if(~(fd = open(ttyfile, O_RDWR)) &&
	(~ft_vector_init(&line_in, LINE_IN_CAP) &&
	(~dad_envv_init(envv))))
		dad_loop(fd);
	return (EXIT_SUCCESS);
}
