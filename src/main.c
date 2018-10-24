/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:01:56 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/24 11:16:27 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

t_vector g_linev;

int		init_envv(char **received_envv)
{
	VAR(unsigned, i, 0);
	VAR(size_t, len, STD_ENVV + ft_arrlen(received_envv));
	if (!(g_envv = ft_memalloc(sizeof(char *) * (len + 1))))
		return (-1);
	while (i < len)
	{
		g_envv[i] = ft_strdup(received_envv[i - STD_ENVV]);
		i++;
	}
	g_envv_len = i;
	g_envv[i] = NULL;
	return (1);
}


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
			if (args[0])
			{
				translate_envv_args(args);
				status = execute(args);
				ft_freestrarr(args);
			}
		}
		ft_vector_free(&g_linev);
	}
	return (status);
}

int		main(int ac, char **av, char **envv)
{
	VAR(int, fd, STDIN_FILENO);
	VAR(const char *, debugtty, NULL);
	if (ac > 1 && ft_strcmp(av[1], "debug") == 0)
	{
		if (ac > 2)
		{
			debugtty = av[2];
			fd = open(debugtty, O_RDWR);
			ft_printf("%s\n", ~fd ? "Debug start @entrypoint main" :
			"Not a valid ttyfile" );
		}
		else
			ft_printf("dsh: debug requires a ttyfile name:\n");
	}
	if (fd >= 0 && ~init_envv(envv))
	{
		loop(fd);
		ft_freestrarr(g_envv);
	}
	return (0);
}
