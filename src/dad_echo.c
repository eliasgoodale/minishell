/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dad_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 14:24:27 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/14 16:12:02 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

void	ft_putstr_esc(char *s, char avoid)
{
	while(*s)
	{
		if(*s != avoid)
			ft_putchar(*s);
		s++;
	}
}

void	echo_out(char *s)
{
	VAR(char *, endquo, NULL);
	VAR(char, quo, *s);
	if(quo == '\"' || quo == '\'')
	{
		endquo = ft_strrchr((s + 1), quo);
		if (endquo && !*(endquo + 1))
			write(1, (s + 1), endquo - (s + 1));
		else
			ft_putstr_esc(s, quo);
	}
	else
		ft_printf("%s", s);
}

int		dadsh_echo(char **args)
{
	VAR(int, i, -1);
	VAR(int, n_flag, 0);
	if(!args[0])
		return(write(1, "\n", 1));
	if(ft_strcmp("-n", args[0]) == 0)
	{
		n_flag = 1;
		++i;
	}
	while(args[++i])
	{
		echo_out(args[i]);
		if(!args[i + 1] && !n_flag)
			ft_putchar('\n');
	}
	return(1);
}