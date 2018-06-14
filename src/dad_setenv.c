/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dad_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:40:11 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/11 14:56:05 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

void	set_envv(char *key, char *val)
{
	VAR(int, pos, find_envv(key));
	VAR(char *, tmp, ft_strjoin("=", val));
	if(g_envv[pos])
	{
		free(g_envv[pos]);
		if (val)
			g_envv[pos] = ft_strjoin(key, tmp);
		else
			g_envv[pos] = ft_strjoin(key, "=");
	}
	else
	{
		g_envv = realloc_envv(pos + 1);
		if (val)
			g_envv[pos] = ft_strjoin(key, tmp);
		else
			g_envv[pos] = ft_strjoin(key, "=");
	}
	free(tmp);
}

int		dadsh_setenv(char **args)
{
	if (!args[0])
	{
		print_env();
		return (1);
	}
	if(arr_len(args) > 2)
	{
		ft_printf("setenv: Too many arguments\n");
		return (1);
	}
	set_envv(args[0], args[1]);
	return (1);
}