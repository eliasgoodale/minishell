/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:45:06 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/23 14:20:53 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_join(char *s1, char *joiner, char *s2)
{
	VAR(int, i, 0);
	VAR(char *, ret, ft_memalloc(sizeof(
		ft_strlen(s1) + ft_strlen(joiner) + ft_strlen(s2) + 1)));
	while (*s1)
	{
		ret[i] = *s1;
		s1++;
		i++;
	}
	while (*joiner)
	{
		ret[i] = *joiner;
		joiner++;
		i++;
	}
	while (*s2)
	{
		ret[i] = *s2;
		s2++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
