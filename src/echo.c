/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:28:00 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/24 17:52:31 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

int		echo(char **args)
{
	VAR(int, i, -1);
	VAR(int, n_flag, 0);
	if (!args[0])
		return (write(1, "\n", 1));
	if (ft_strcmp("-n", args[0]) == 0)
	{
		n_flag = 1;
		i++;
	}
	while (args[++i])
		ft_printf("%s%s", args[i], args[i + 1] ? " " : "");
	n_flag ? 0 : write(1, "\n", 1);
	return (1);
}
