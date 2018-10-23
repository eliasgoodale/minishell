/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepend_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 11:48:03 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/23 14:20:53 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_prepend_str(char *prefix, char *suffix)
{
	VAR(char*, ret, NULL);
	VAR(int, i, -1);
	VAR(int, j, -1);
	if (!(ret = (char *)malloc(sizeof(char) *
		(ft_strlen(prefix) + ft_strlen(suffix) + 1))))
		return (NULL);
	while (prefix[++i])
		ret[i] = prefix[i];
	while (suffix[++j])
		ret[i++] = suffix[j];
	ret[i] = '\0';
	return (ret);
}
