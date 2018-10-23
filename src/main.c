/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:17:14 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/18 15:41:57 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

int		main(int ac, char **envv)
{
	char *ttyfile = "/dev/ttys001";
	int fd;
	t_vector	line_in;

	if(~(fd = open(ttyfile, O_RDWR)) &&
	(~ft_vector_init(&line_in, LINE_IN_CAP) &&
	(~dad_envv_init(envv))))
		dad_loop(fd);
	return (EXIT_FAILURE);
}
