/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 15:29:03 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/23 15:37:21 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

void	set_variable(char *key, char *val)
{
	VAR(int, pos, find_envv(key));
	VAR(char *, new_val, ft_strjoin("=", val));
	if (~pos)
	{
		free(g_envv[pos]);
		g_envv[pos] = NULL;
		if (val)
			g_envv[pos] = ft_strjoin(key, new_val);
		else
			g_envv[pos] = ft_strjoin(key, "=");
	}
	else
	{
		g_envv = realloc_envv(g_envv_len + 1);
		if (val)
			g_envv[g_envv_len - 1] = ft_strjoin(key, new_val);
		else
			g_envv[g_envv_len - 1] = ft_strjoin(key, "=");
	}
	free(new_val);
	free(key);
}

int		set_env(char **args)
{
	VAR(int, i, -1);
	VAR(char *, val, NULL);
	VAR(char *, key, NULL);
	while (args[++i])
	{
		val = ft_strchr(args[i], '=');
		key = get_envv_key(args[i]);
		if (key && val)
			set_variable(key, (val + 1));
		else
		{
			free(key);
			ft_printf("No Assignment: USAGE: setenv KEY=VAL\n");
		}
	}
	return (1);
}
