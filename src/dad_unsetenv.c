/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dad_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:53:35 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/14 14:46:43 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

char	**realloc_envv(int new_size)
{
	VAR(int, i, -1);
	VAR(char**, envv_ref, ft_memalloc(sizeof(char *) * (new_size + 1)));
	while (g_envv[++i] && i < new_size)
	{
		free(g_envv[i]);
		envv_ref[i] = ft_strdup(g_envv[i]);
	}
	free(g_envv);
	g_envv_sz = new_size;
	return (envv_ref);
}

void	remove_envv(int var_pos)
{
	VAR(int, i, var_pos);
	VAR(int, edit_pos, var_pos + 1);
	free(g_envv[var_pos]);
	while(g_envv[edit_pos])
	{
		g_envv[i] = ft_strdup(g_envv[edit_pos]);
		free(g_envv[edit_pos]);
		edit_pos++;
		i = edit_pos - 1;
	}
	g_envv = realloc_envv(g_envv_sz - 1);
}

int		dadsh_unsetenv(char **args)
{
	VAR(int, i, -1);
	VAR(int, var_pos, 0);
	if(!args[0])
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
	return (1);
}