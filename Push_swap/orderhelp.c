/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderhelp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 02:00:12 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/08/15 17:21:50 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_less(t_stack a, t_stack b, int elm)
{
	int i;
	int j;
	int re;

	i = 0;
	j = 0;
	re = 0;
	while (i < a.size)
	{
		if (a.tab[i] < elm)
			re++;
		i++;
	}
	while (j < b.size)
	{
		if (b.tab[j] < elm)
			re++;
		j++;
	}
	return (re);
}

int		ft_oless(t_stack b, int elm)
{
	int j;
	int re;

	j = 0;
	re = 0;
	while (j < b.size)
	{
		if (b.tab[j] < elm)
			re++;
		j++;
	}
	return (re);
}

int		direction(t_stack a, int l)
{
	int		s;
	int		f;
	t_stack	b;
	int		re;

	s = 0;
	f = 0;
	b.size = 0;
	while (ft_less(a, b, a.tab[a.size - 1 - s]) > l)
		s++;
	while (ft_less(a, b, a.tab[f]) > l)
		f++;
	re = (s < f) ? 1 : -1;
	return (re);
}
