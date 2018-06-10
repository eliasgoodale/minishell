/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadsh_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:48:23 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/09 18:05:22 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"
#include "../include/cmd_tbl.h"

int		dadsh_exec(char **args)
{
	int i;

	i = 0;
	if(args[0] == NULL)
		return (1);
	while(i < MAX_BUILTINS)
	{
		if (ft_strcmp(args[0], builtin_str[i]) == 0)
			return(g_dadsh_cmds[i](args));
		i++;
	}
	return (dadsh_launch(args));
}

void	put_help_msg(void)
{
	int i;

	i = 0;
	ft_printf("Dadshell: v 0.0.1\n");
	ft_printf("Instructional help goes here\n");
	ft_printf("The following builtins are present in this shell:\n");
	ft_printf("Use man command for information on other programs");
	return ;
}

int 	dadsh_cd(char **args)
{
	if (args[1] == NULL)
		ft_printf("dadsh: expected argument to \"cd\"\n");
	else
	{
		if (chdir(args[1]))
			throw_err("dadsh");
	}
	return (1);
}

int		dadsh_help(char **args)
{
	(void)args;
	put_help_msg();
	return (1);
}

int		dadsh_exit(char **args)
{
	(void)args;
	return (0);
}