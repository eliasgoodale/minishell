/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:01:56 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/23 13:30:20 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

t_vector g_linev;

int		loop(int fd)
{
	VAR(int, status, 1);
	VAR(char **, args, NULL);
	while (~status && status)
	{
		ft_printf("> ");
		signal(SIGINT, handle_signal);
		if ((args = get_user_input(fd)))
		{
			status = args[0] ? execute(args) : 1;
			ft_freestrarr(args);
		}
		ft_vector_free(&g_linev);
	}
	return (status);
}

int		main(int ac, char **envv)
{
	VAR(int, fd, STDIN_FILENO);
	VAR(const char *, debugtty, "/dev/ttys001");
	VAR(int, i, 1);
	if (ac > 1 && ft_strcmp(envv[i], "debug") == 0)
	{
		fd = open(debugtty, O_RDWR);
		i++;
	}
	if (fd >= 0 && ~init_envv(&envv[i]))
	{
		loop(fd);
		ft_freestrarr(g_envv);
	}
	return (0);
}
