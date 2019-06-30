/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_msc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:51:02 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/29 15:00:29 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/pf_colors.h"

int64_t	*ft_printf_n_len(t_arg *inf, va_list ap)
{
	if (inf->length == hh)
		return ((int64_t *)va_arg(ap, signed char *));
	if (inf->length == h)
		return ((int64_t *)va_arg(ap, short *));
	if (inf->length == l)
		return ((int64_t *)va_arg(ap, long *));
	if (inf->length == ll)
		return ((int64_t *)va_arg(ap, long long *));
	if (inf->length == j)
		return ((int64_t *)va_arg(ap, int64_t *));
	if (inf->length == z)
		return ((int64_t *)va_arg(ap, ssize_t *));
	return ((int64_t *)va_arg(ap, int *));
}

void		handle_pos(t_vector *vector, t_arg *inf, va_list ap)
{
	int64_t	*i;
	int			tmp;

	tmp = vector->len;
	i = ft_printf_n_len(inf, ap);
	*i = (int64_t)tmp;
}

void		handle_percent(t_vector *vector, t_arg *inf, va_list ap)
{
	char *str;

	(void)ap;
	str = ft_strnew(1);
	*str = inf->spec;
	add_padding(inf, &str);
	ft_vector_append(vector, str);
	free(str);
}

int			handle_color(t_vector *vector, t_arg *inf, char **format)
{
	int i;

	i = -1;
	ft_vector_nappend(vector, *format, inf->rc);
	*format += inf->rc;
	while (++i < 33)
		if (ft_strnstr(*format, g_colortab[i].kw_name,
					ft_strlen(g_colortab[i].kw_name)))
		{
			ft_vector_append(vector, g_colortab[i].code);
			*format += ft_strlen(g_colortab[i].kw_name);
			inf->rc = -1;
			return (1);
		}
	return (0);
}
