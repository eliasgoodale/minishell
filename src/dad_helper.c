/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dad_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:42:56 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/11 13:22:46 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

int		arr_len(char **envv)
{
	int len;

	len = -1;
	while(envv[++len])
		;
	return (len);
}

void	ft_freestrarr(char **arr)
{
	VAR(int, i, -1);
	while(arr[++i])
	{	
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
}

void			print_env(void)
{
	int		i;

	i = -1;
	while (g_envv[++i])
		ft_printf("%s\n", g_envv[i]);
}

int				arr_len(char **envv)
{
	VAR(int, i, -1);
	while(envv[i])
		i++;
	return (i + STD_ENV);
}


char		*get_envv(char *var)
{
	VAR(int, i, -1);
	VAR(int, var_len, ft_strlen(var));
	while(g_envv[++i])
		if(ft_strncmp(g_envv[i], var, var_len) == 0)
			return(ft_strchr(g_envv[i], '=') + 1);
	return (NULL);
}

int 	find_envv(char *var)
{
	VAR(int, i, -1);
	VAR(int, var_len, ft_strlen(var));
	while(g_envv[++i])
		if(ft_strncmp(g_envv[i], var, var_len) == 0)
			return(i);
	return (NULL);
}

