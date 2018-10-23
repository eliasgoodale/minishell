/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 11:49:35 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/29 11:37:22 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
*	The Lehmer Generator or "multipicative congruential random-number generator"
*	is based on the recursion: Xᵢ₊₁ = g * Xᵢ mod n
*	Xᵢ is the value at iteration i, used to generate the next value Xᵢ₊₁ and
*	a is a multiplier. If (g * X) ≥ 0 && m > 0 the modulo function is the residue,
*	g * X - RES(g * X / m) * m. For example,
*		n: prime number or power of a prime	
*		
*
*		a: th
*		c: 
*		the first X is t
*	These integer constants specify the generator.
*/
/*
double  ft_rand(int seed)
{
	VAR(long, rseed, !seed ? 123456789 : seed);
	VAR(const long, m, 2147483647);
	VAR(const long, mult, 48271);
	VAR(const long, q, m / mult);
	VAR(const long, r, m % mult);
	VAR(long, t, mult * (rseed % q) - r * (rseed / q));
	if (t > 0)
		rseed = t;
	else
		rseed = t + m;
	return ((double)rseed / m);
}
*/

int		ft_lehmer(int seed)
{
	static int rseed;
	int u;
	int ret;
	if (!rseed)
		rseed = seed ? seed : 123456789;
	u = seed / 2147483647;
	rseed = (48271 * rseed + )

}