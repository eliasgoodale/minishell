/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last_any.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 09:54:40 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/24 12:12:44 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*find_last_any(char *haystack, const char *any)
{
	VAR(char *, ret, NULL);
	VAR(char *, tmp, NULL);
	while (*any)
	{
		if ((tmp = ft_strrchr(haystack, *any)) && ret)
			ret = tmp > ret ? tmp : ret;
		else if (tmp)
			ret = tmp;
		any++;
	}
	return (ret);
}
