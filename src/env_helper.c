/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:54:05 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/24 12:54:36 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

char **g_envv;
size_t g_envv_len;

char	*get_envv_val(char *key)
{
	VAR(int, i, -1);
	VAR(size_t, len, ft_strlen(key));
	while (g_envv[++i])
		if (ft_strncmp(g_envv[i], key, len) == 0)
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

void	translate_envv_args(char **args)
{
	int i;
	char *key;
	char *val;
	char *start;
	char *envv_start;

	t_vector translated;

	i = -1;
	while (args[++i])
	{
		if(!(start = ft_strchr(args[i], '$')))
			continue;
		ft_vector_init(&translated, 50);
		ft_vector_nappend(&translated, args[i], start - args[i]);
		while((envv_start = ft_strchr(start, '$')))
		{
			start = find_next_any(envv_start, SEPARATORS);
			key = ft_strndup(envv_start + 1, (start - envv_start - 1));
			val = get_envv_val(key);
			ft_vector_append(&translated, val ? val : "");
			ft_vector_nappend(&translated, start, envv_start - start);
			free(key);
		}
		free(args[i]);
		args[i] = ft_strdup(translated.data);
		ft_vector_free(&translated);
	}
}
