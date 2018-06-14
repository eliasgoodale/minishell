/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadsh_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:48:23 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/13 17:57:07 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

int 	dadsh_cd(char **args)
{
	VAR(char *, home_path, get_envv("HOME"));
	VAR(char *, full_path, NULL);
	if (args[1] == NULL)
		chdir(home_path);
	else
	{
		if (args[1][0] == '~')
		{
			full_path = ft_prepend_str(home_path, &args[1][1]);
			if(chdir(full_path))
				ft_printf("No such file or directory");
			free(full_path);
		}
		else if (chdir(args[1]))
			ft_printf("No such file or directory\n");
	}
	return (1);
}
