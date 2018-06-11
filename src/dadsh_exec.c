/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadsh_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:23:27 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/10 15:36:09 by egoodale         ###   ########.fr       */
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

int		dadsh_help(char **args)
{
	VAR(int, i, -1);
	(void)args;
	ft_printf("Dadshell: v 0.0.1\n");
	ft_printf("Instructional help goes here\n");
	ft_printf("The following builtins are present in this shell:\n");
	while(builtin_str[i])
		ft_printf("%d: %s\n", i + 1, builtin_str[i]);
	ft_printf("Use man command for information on other programs\n");
	return (1);
}

int		dadsh_exit(char **args)
{
	(void)args;
	return (0);
}