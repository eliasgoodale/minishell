/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dad_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:27:15 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/18 15:57:17 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

void     quote_message(char quote)
{
	if (quote == '\'')
		ft_printf("\nsquote> ");
	else if (quote == '\"')
		ft_printf("\ndquote> ");
	else
		ft_printf("\nbquote> ");
}

char		**normalize_input(char *input)
{
	VAR(char **, args, ft_memalloc(sizeof(char *) * g_exec_args));
	VAR(char *, tok, ft_strtok(input, g_quotes));
	VAR(int, i, 0);
	while(tok)
	{
		args[i++] = ft_strdup(tok);
		tok = ft_strtok(input, g_quotes);
	}
	args[i] = NULL;
	return(args);
}

void         prompt_user(t_vector *v, char *opnq, char *clsq, int fd)
{
    if (!opnq || !*opnq || fd < 0)
        return ;
    if ((clsq = ft_strchr(opnq + 1, *opnq)))
	{
		if(!(opnq = find_next_any(clsq + 1, g_quotes)))
			opnq = v->data + v->len;
    	prompt_user(v, &(*opnq), clsq, fd);
		*opnq ? ft_subvector_slide(clsq, opnq, 1) :
			ft_subvector_slide(clsq, opnq, 1);
	}
	else
	{
		quote_message(*opnq);
		g_exec_args++;
		fd = dad_input(v, &(*opnq), NULL, fd);
		prompt_user(v, opnq, clsq, fd);
	}

}

char		**dad_input(t_vector *line_in, char *opnq, char *clsq, int fd)
{
	char *line;
	size_t len;

	if(~fd && ~get_next_line(fd, &line))
	{
		len = ft_strlen(line);
		ft_vector_append(line_in, line);
		if (clsq)
		{
			opnq = find_next_any(clsq, g_quotes);
			prompt_user(line_in, &(*opnq), clsq, fd);
			if (opnq)
				ft_subvector_slide(line_in, opnq, clsq, 1);
		}
		else
			ft_vector_append(line_in, "\n");
		return(normalize_input(line_in->data));
	}
	return (NULL);
}