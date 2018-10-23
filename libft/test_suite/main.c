/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 12:25:10 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/29 11:37:00 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
int m = 2147483647;
int a = 48271;
int q = 44488;
int r = 3399;

double		ft_lehmer(int seed)
{
	static double rseed;
	double h;
	int    l;
  double t;

	if (!rseed)
		rseed = seed ? seed : 123456789;
	h = rseed / q;
  l = rseed % q;
  t = a * 1 - r * h;
  if (t > 0)
    rseed = t;
  else
    rseed = t + m;
	return ((double)rseed / m);
}
int main(void)
{

    /*
    ** ft_skipspace
    */
    char *s = "           hello";
    s = ft_skipspace(s);
    ft_printf("%s\n", s);

    /*
    ** ft_atoi
    */
    char *a = "              87314636          '    ";
    int i = ft_atoi(a);
    ft_printf("%d\n", i);

    /*
    ** ft_lcm
    */

   int lcm = ft_lcm(72, 120);
   ft_printf("lcm: %d\n", lcm);

   /*
   ** ft_rand
   */
  double u;
  for(int i = 1; i < 1000; i++)
  {
    u = ft_lehmer(i);
    ft_printf("%f\n", u);
  }
}