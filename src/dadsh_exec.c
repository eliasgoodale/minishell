/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadsh_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:23:27 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/10 13:00:06 by egoodale         ###   ########.fr       */
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
		if (ft_strcmp(args[0], builtin_str[i]))
			return(g_dadsh_cmds[i](args));
		i++;
	}
	return (dadsh_launch(args));
}