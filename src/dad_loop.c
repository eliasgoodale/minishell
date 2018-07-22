/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dad_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 12:02:16 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/21 18:22:33 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

void dad_loop(int fd, t_vector	*line_in)
{
	int status;

	status = 1;
	while (~fd && ~status && status)
	{
		ft_printf("\n> ");
		signal(SIGINT, dad_signal);
		if(~(fd = dad_input(fd, line_in)))
			status = dadsh_exec(line_in->data);
	}
	ft_freestrarr(g_envv);
}
