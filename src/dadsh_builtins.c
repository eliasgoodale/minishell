/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadsh_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:48:23 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/10 17:44:36 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

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

int		dadsh_env(char **args)
{

}

int		dadsh_setenv(char **args)
{

}
