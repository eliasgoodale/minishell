/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadsh_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 19:17:38 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/21 10:34:44 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

char	*std_envvlist[] = { 
	"PATH=/bin/",
	"HOME=/nfs/2018/e/egoodale/", 
	"MAIL=eligoodale1@gmail.com"
};

int		dad_init_envv(char **custom)
{
	VAR(int, envvs, STD_ENVV + ft_arrlen(custom));
	VAR(int, i, -1);
	VAR(int, j, 0);
	if (~ft_vectorspace_init(&g_envv, DAD_PATH_MAX, envvs))
	{
		while(++i < STD_ENVV)
			ft_vector_append(&g_envv[i], std_envvlist[i]);
		while (++i < envvs)
		{
			ft_vector_append(&g_envv[i], custom[j]);
			j++;
		}
		return (0);
	}
	return (-1);
}
