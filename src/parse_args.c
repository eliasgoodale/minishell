/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:03:12 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/24 18:27:19 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

void	parse_arg(t_vector *t, char **envv_tok)
{
	VAR(char *, key, NULL);
	VAR(char *, val, NULL);
	VAR(char *, separator, NULL);
	while(*envv_tok)
	{
		if (!(separator = find_next_any(*envv_tok, SEPARATORS)))
			separator = ft_strchr(*envv_tok, '\0');
		key = ft_strndup(*envv_tok, separator - *envv_tok);
		val = find_envv(key, 1);
		ft_vector_append(t, val ? val : "");
		ft_vector_nappend(t, separator, ft_strlen(separator));
		*envv_tok = ft_strtok(NULL, "$");
		free(key);
	}
}

void	translate_envv_args(char **args)
{
	int i;
	char *envv_token;
	t_vector translated;

	i = -1;
	while (args[++i])
	{
		if(!ft_strchr(args[i], '$'))
			continue;
		envv_token = ft_strtok(args[i], "$");
		ft_vector_init(&translated, 50);
		if (envv_token != (args[i] + 1))
		{
			ft_vector_append(&translated, envv_token);
			envv_token = ft_strtok(NULL, "$");
		}
		parse_arg(&translated, &envv_token);
		free(args[i]);
		args[i] = ft_strdup(translated.data);
		ft_vector_free(&translated);
	}
}
