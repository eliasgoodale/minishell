/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dad_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 16:42:56 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/15 10:01:28 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"



int		print_env(void)
{
	int		i;

	i = -1;
	while (g_envv[++i])
		ft_printf("%s\n", g_envv[i]);
	return(1);
}

int				arr_len(char **envv)
{
	VAR(int, i, 0);
	while(envv[i])
		i++;
	return (i);
}

char		*get_envv_val(char *envv_str)
{
	VAR(int, i, -1);
	VAR(int, var_len, ft_strlen(envv_str));
	while(g_envv[++i])
		if(ft_strncmp(g_envv[i], envv_str, var_len) == 0)
			return(ft_strchr(g_envv[i], '=') + 1);
	return (NULL);
}

int 	find_envv(char *var)
{
	VAR(int, i, -1);
	VAR(int, var_len, ft_strlen(var));
	while(g_envv[++i])
		if(ft_strncmp(g_envv[i], var, var_len) == 0)
			break ;
	return (i);
}

char	*split_envv_key(char *envv_str)
{
	VAR(char *, ret, NULL);
	VAR(int, len, 0);
	len = ft_strchr(envv_str, '=') - envv_str;
	ret = ft_strndup(envv_str, len + 1);
	ret[len] = '\0';
	return (ret);
}