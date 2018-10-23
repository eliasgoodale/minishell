/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 12:01:48 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/15 12:10:40 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char    *ft_skipspace(char *s)
{
    VAR(const char *, space_chars, " \t\n\v\r\f");
    while(ft_strchr(space_chars, *s))
        s++;
    return (s);
}