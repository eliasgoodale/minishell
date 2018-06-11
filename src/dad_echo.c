/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dad_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 14:24:27 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/10 16:42:32 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

void	echo_out(char *str)
{
	VAR(char *, endquo, NULL);
	VAR(char, quo, *str);
	if(quo == '\"' || '\'')
	{
		endquo = ft_strrchr((str + 1), quo);
		if (endquo && !*(endquo + 1))
			write(1, (str + 1), endquo - (str + 1));
		else   // can put in hang function for input here
			write(1, str, ft_strlen(str));
	}
	else
		ft_printf("%s", str);
}

int		dadsh_echo(char **args)
{
	VAR(int, i, -1);
	VAR(int, n_flag, 0);
	if(!*args)
	{
		write(1, "\n", 1);
		return (1);
	}
	if(ft_strcmp("-n", args[0]) == 0)
	{
		n_flags = 1;
		++i;
	}
	while(args[++i])
	{
		echo_out(args[i]);
		if(!args[i + 1] && !n_flags)
			ft_putchar('\n');
	}
	return(1);
}