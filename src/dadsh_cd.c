/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadsh_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:48:23 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/14 09:35:24 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

int 	dadsh_cd(char **args)
{
	VAR(char *, home_path, get_envv_val("HOME"));
	VAR(char *, full_path, NULL);
	if (args[0] == NULL)
		chdir(home_path);
	else
	{
		if (args[0][0] == '~')
		{
			full_path = ft_prepend_str(home_path, &args[1][1]);
			if(chdir(full_path))
				ft_printf("No such file or directory");
			free(full_path);
		}
		else if (chdir(args[0]))
			ft_printf("No such file or directory\n");
	}
	return (1);
}