/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 11:31:41 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/23 13:22:08 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

int		is_in(char *directory_name, char *executable)
{
	VAR(DIR *, directory, opendir(directory_name));
	VAR(t_dirent *, entry, NULL);
	if (!directory)
		return (0);
	while ((entry = readdir(directory)))
	{
		if (ft_strcmp(entry->d_name, executable) == 0)
		{
			closedir(directory);
			return (1);
		}
	}
	closedir(directory);
	return (0);
}

void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n>");
		signal(SIGINT, handle_signal);
	}
}
