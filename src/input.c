/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:46:14 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/23 13:26:41 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

const char	*g_quotes = "\'\"`";
char		*g_openq;
char		*g_closeq;

#define ISQ(x) (x == '\'' || x == '\"' || x =='`' ? 1 : 0)

void	quote_message(char quote)
{
	if (quote == '\'')
		ft_printf("\nquote> ");
	else if (quote == '\"')
		ft_printf("\ndquote> ");
	else
		ft_printf("\nbquote> ");
}

char	**normalize_input(char *input)
{
	VAR(int, i, -1);
	VAR(int, quotes, 0);
	VAR(char*, parsed, NULL);
	VAR(char **, args, NULL);
	while (input[++i])
		if (ISQ(input[i]))
			quotes++;
	parsed = ft_memalloc((ft_strlen(input) - quotes) + 1);
	i = 0;
	while (*input)
	{
		while (ISQ(*input))
			input++;
		parsed[i] = *input;
		i++;
		input++;
	}
	args = ft_strsplit(parsed, ' ');
	free(parsed);
	return (args);
}

int		initialize_linefeed(int fd)
{
	char *line;

	if (~ft_vector_init(&g_linev, 50) && get_next_line(fd, &line))
	{
		ft_vector_append(&g_linev, line);
		g_closeq = g_linev.data;
		free(line);
		return (1);
	}
	else
		return (-1);
}

char	**parse_quotes(int fd)
{
	char *line;
	char seek;
	char *space;

	while ((g_openq = find_next_any(g_closeq, g_quotes)))
	{
		seek = *g_openq;
		space = ft_strchr(g_closeq, ' ');
		while (!(g_closeq = ft_strchr(g_openq + 1, seek)))
		{
			quote_message(seek);
			get_next_line(fd, &line);
			ft_vector_append(&g_linev, line);
			ft_vector_append(&g_linev, "\n");
			free(line);
		}
		if (*(g_closeq + 1) != seek)
			g_closeq++;
	}
	return (normalize_input(g_linev.data));
}

char	**get_user_input(int fd)
{
	if (~initialize_linefeed(fd))
	{
		if (find_next_any(g_closeq, g_quotes))
			return (parse_quotes(fd));
		else
			return (ft_strsplit(g_linev.data, ' '));
	}
	return (NULL);
}
