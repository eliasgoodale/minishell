/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dad_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:53:35 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/10 18:20:02 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

char	**realloc_env(int new_size)
{
	VAR(int, i, -1);
	VAR(char**, new, ft_memalloc(sizeof(char *) * (new_size + 1)))
	while (g_envv[++i] && i < new_size)
	{
		new[i] = ft_strdup(g_envv[i]);
		free(g_envv[i]);
	}
	free(g_envv);
	return (new);
}

void	remove_envv(int var_pos)
{
	VAR(int, i, var_pos);
	VAR(int, var_count, var_pos + 1);
	free(g_envv[var_pos]);
	g_envv[var_pos] = NULL;
	while(g_envv[var_count])
	{
		g_envv[i] = ft_strdup(g_envv[var_count]);
		free(g_envv[var_count]);
		var_count++;
		i = var_count - 1;
	}
	g_envv = realloc_envv(var_count - 1);
}

int		dad_unsetenv(char **args)
{
	VAR(int, i, -1);
	VAR(int, var_pos, 0);
	if(!*args)
	{
		ft_printf("unsetenv: Too few arguments.");
		return (1);
	}
	while(args[++i])
	{
		var_pos = find_envv(args[i]);
		if (g_envv[var_pos])
			remove_envv(var_pos);
	}

}