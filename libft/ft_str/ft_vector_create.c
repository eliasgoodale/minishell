/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 18:05:47 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/23 14:20:53 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_vector	**ft_vectorspace_create(size_t init_cap, size_t size)
{
	VAR(size_t, i, -1);
	VAR(t_vector **, vspace, NULL);
	if (!(vspace = ft_memalloc(sizeof(t_vector *) * size)))
		return (NULL);
	while (++i < size)
		if ((vspace[i] = ft_vector_create(init_cap)))
			continue ;
		else
		{
			ft_vectorspace_free(&vspace[0], i);
			return (NULL);
		}
	return (vspace);
}

t_vector	*ft_vector_create(size_t init_cap)
{
	VAR(t_vector *, new_vector, NULL);
	if (init_cap && (new_vector = ft_memalloc(sizeof(t_vector))))
	{
		new_vector->len = 0;
		new_vector->cap = init_cap;
		new_vector->data = ft_memalloc(sizeof(init_cap));
		return (new_vector);
	}
	return (NULL);
}

void		ft_vectorspace_free(t_vector **vspace, int size)
{
	VAR(int, i, -1);
	while (++i < size)
	{
		free(vspace[i]->data);
		free(vspace[i]);
		vspace[i] = NULL;
	}
}

void		ft_subvector_slide(char *data, char *targ, size_t data_len)
{
	VAR(int, orient, targ >= data ? 1 : -1);
	VAR(char *, start, ~orient ? data : data + (data_len - 1));
	VAR(char *, subt, start + (orient * data_len));
	VAR(int, shifts, ~orient ? (targ - subt) : (subt - targ));
	if (shifts < (int)(~orient ? data_len : data_len - 1))
		return ;
	while (shifts-- != (~orient ? 0 : -1))
	{
		ft_charswap(start, subt);
		start += orient;
		subt += orient;
	}
	ft_subvector_slide(start, targ, data_len);
}
