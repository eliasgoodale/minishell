/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:54:05 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/23 13:12:19 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

char **g_envv;
size_t g_envv_len;
const char *g_std_envvlist[] = {
	"PATH=/bin/:/usr/bin/",
	"HOME=/nfs/2018/e/egoodale/",
	"TERM=xterm-256color"
};

char	*get_envv_val(char *envv_name)
{
	VAR(int, i, -1);
	VAR(size_t, len, ft_strlen(envv_name));
	while (g_envv[++i])
		if (ft_strncmp(g_envv[i], envv_name, len) == 0)
			return (ft_strchr(g_envv[i], '=') + 1);
	return (NULL);
}

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

int		find_envv(char *key)
{
	VAR(int, i, -1);
	VAR(int, key_len, ft_strlen(key));
	while (g_envv[++i])
		if (ft_strncmp(g_envv[i], key, key_len) == 0)
			break ;
	return ((size_t)i == g_envv_len ? -1 : i);
}

int		init_envv(char **received_envv)
{
	VAR(unsigned, i, 0);
	VAR(size_t, len, STD_ENVV + ft_arrlen(received_envv));
	if (!(g_envv = ft_memalloc(sizeof(char *) * (len + 1))))
		return (-1);
	while (i < STD_ENVV)
	{
		g_envv[i] = ft_strdup(g_std_envvlist[i]);
		i++;
	}
	while (i < len)
	{
		g_envv[i] = ft_strdup(received_envv[i - STD_ENVV]);
		i++;
	}
	g_envv_len = i;
	g_envv[i] = NULL;
	return (1);
}
