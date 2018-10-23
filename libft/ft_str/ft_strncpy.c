/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:16:06 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/23 14:20:53 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strncpy(const char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	char			*cpy;

	i = 0;
	cpy = (char *)dest;
	while (*(src + i) && i < n)
	{
		*(cpy + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(cpy + i) = '\0';
		i++;
	}
	return (cpy);
}
