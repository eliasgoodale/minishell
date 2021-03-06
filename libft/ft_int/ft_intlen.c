/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 10:31:55 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/23 14:20:53 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_intlen(int64_t n)
{
	int len;

	if (n > LLONG_MAX || n < LLONG_MIN)
		return (20);
	if (n == LLONG_MIN || n == LLONG_MAX)
		return (19);
	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		n = -n;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
