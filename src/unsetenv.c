/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:23:29 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/24 18:27:55 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

void	remove_envv(int var_pos)
{
	VAR(int, i, var_pos);
	VAR(int, edit_pos, var_pos + 1);
	free(g_envv[var_pos]);
	while (g_envv[edit_pos])
	{
		g_envv[i] = ft_strdup(g_envv[edit_pos]);
		free(g_envv[edit_pos]);
		edit_pos++;
		i = edit_pos - 1;
	}
	g_envv = realloc_envv(g_envv_len - 1);
}

int		unset_env(char **args)
{
	VAR(int, i, -1);
	VAR(int, var_pos, 0);
	VAR(char *, key, NULL);
	if (!args[0])
		ft_printf("unsetenv: Too few arguments.\n");
	while (args[++i])
	{
		key = get_envv_key(args[i]);
		var_pos = get_envv_index(key);
		if (~var_pos)
			remove_envv(var_pos);
		else
			ft_printf("%s is not an env variable\n", key);
		free(key);
	}
	return (1);
}
