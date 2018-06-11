/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:17:14 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/10 15:14:30 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

void dad_loop(int fd)
{
	char *line;
	char **args;
	int status;

	status = 1;
	while (status)
	{
		ft_printf("\n> ");
		get_next_line(fd, &line);
		args = ft_strsplit(line, ' ');
		status = dadsh_exec(args);
		free(line);
		free(args);
	}
		
}

int main(int ac, char **av, char **env)
{
	char *ttyfile = av[1];
	int fd = open(ttyfile, O_RDWR);
	//init_shell(fd, env);
	dad_loop(fd);
	return (EXIT_SUCCESS);
}