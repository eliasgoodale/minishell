/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:17:14 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/11 12:46:22 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

int		env_len(char **envv)
{
	int len;

	len = -1;
	while(env[++len])
		;
	return (len);
}

void	ft_freestrarr(char **arr)
{
	VAR(int, i, -1);
	while(arr[++i])
	{	
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
}

void dad_loop(int ttyfd)
{
	char *line;
	char **args;
	int status;

	status = 1;
	while (status)
	{
		ft_printf("\n> ");
		signal(SIGINT, dad_signal);
		get_next_line(ttyfd, &line);
		args = ft_strsplit(line, ' ');
		free(line);
		status = dadsh_exec(args);
		ft_freestrarr(args);
	}
	ft_freestrarr(g_envv);
	return (0);
}

int main(int ac, char **av, char **env)
{
	char *ttyfile = av[1];
	int fd = open(ttyfile, O_RDWR);
	init_shell(fd, env);
	dad_loop(fd);
	return (EXIT_SUCCESS);
}