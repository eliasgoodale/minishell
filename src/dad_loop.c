/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dad_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 12:02:16 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/18 16:00:53 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

void dad_loop(int fd, t_vector	*line_in)
{
	int status;
	char **args;
	
	status = 1;
	while (~fd && ~status && status)
	{
		ft_printf("\n> ");
		signal(SIGINT, dad_signal);
		if((args = dad_input(line_in, NULL, line_in->data, fd)))
			status = dad_exec(args);
		g_exec_args = 1;
	}
}
