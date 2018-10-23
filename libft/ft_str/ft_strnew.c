/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:00:39 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/17 13:19:17 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	char	*new_str;

	if (!(new_str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(new_str, '\0', (size + 1));
	return (new_str);
}
