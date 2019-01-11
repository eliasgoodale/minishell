/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 11:31:41 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/24 11:56:36 by egoodale         ###   ########.fr       */
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

int		matches_path(char *path_to_match, char *path)
{
	VAR(char *, executable, find_last_any(path, "/"));
	VAR(size_t, match_len, ft_strlen(path_to_match));
	VAR(size_t, num_chars_to_compare, executable - path);
	if (match_len == num_chars_to_compare && ft_strncmp(path_to_match, path, match_len) == 0)
		return (1);
	return (0);
}
