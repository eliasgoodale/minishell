/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:54:05 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/24 18:29:02 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

char **g_envv;
size_t g_envv_len;


char	*get_envv_key(char *envv_str)
{
	VAR(char *, ret, NULL);
	VAR(int, len, 0);
	VAR(char *, eq, ft_strchr(envv_str, '='));
	len = eq ? eq - envv_str : ft_strlen(envv_str);
	ret = ft_strndup(envv_str, len + 1);
	ret[len] = '\0';
	return (ret);
}

int		get_envv_index(const char *key)
{
	VAR(int, i, -1);
	VAR(char *, eq, NULL);
	VAR(size_t, key_len, 0);
	while(g_envv[++i])
	{
		if (!(eq = ft_strchr(g_envv[i], '=')))
			continue;
		key_len = eq - g_envv[i];
		if(!ft_strncmp(g_envv[i], key, key_len))
			return (i);
	}
	return (-1);
}

char	**realloc_envv(int new_size)
{
	VAR(int, i, -1);
	VAR(char**, envv_ref, ft_memalloc(sizeof(char *) * (new_size + 1)));
	while (g_envv[++i] && i < new_size)
	{
		envv_ref[i] = ft_strdup(g_envv[i]);
		free(g_envv[i]);
	}
	g_envv_len = new_size;
	envv_ref[g_envv_len] = NULL;
	free(g_envv);
	return (envv_ref);
}

char	*find_envv(const char *key, int val_only)
{
	VAR(int, index, get_envv_index(key));
	if (~index)
	{
		if (val_only)
			return (ft_strchr(g_envv[index], '=') + 1);
		else
			return (g_envv[index]);
	}
	return (NULL);
}
