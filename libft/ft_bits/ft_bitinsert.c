/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:34:45 by egoodale          #+#    #+#             */
/*   Updated: 2018/10/23 14:20:53 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

u_int64_t		ft_bitinsert(u_int64_t nb, u_int64_t ins,
								unsigned lb, unsigned ub)
{
	VAR(u_int64_t, all_ones, ~0);
	VAR(u_int64_t, left, all_ones << (ub + 1));
	VAR(u_int64_t, right, ((1 << lb) - 1));
	VAR(u_int64_t, mask, (left | right));
	VAR(u_int64_t, nb_cleared, nb & mask);
	VAR(u_int64_t, m_shifted, ins << lb);
	return (nb_cleared | m_shifted);
}
