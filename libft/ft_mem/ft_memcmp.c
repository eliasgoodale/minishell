/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:56:35 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/23 14:20:53 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;
	size_t			i;

	i = -1;
	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	while (++i < n && *(tmp_s1 + i) == *(tmp_s2 + i))
		;
	if (i == n)
		return (0);
	return (*(tmp_s1 + i) - *(tmp_s2 + i));
}
