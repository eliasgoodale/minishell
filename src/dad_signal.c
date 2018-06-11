/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dad_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:23:00 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/10 18:25:36 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dadshell.h"

void	dad_signal(int sig)
{
	if(sig == SIGINT)
	{
		ft_printf("\n");
		ft_printf("> ");
		signal(SIGINT, dad_signal);
	}
}