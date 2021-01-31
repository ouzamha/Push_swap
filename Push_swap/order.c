/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 18:34:53 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/09/19 20:20:36 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_direction(t_stack a, int l)
{
	int i;
	int re;

	i = 0;
	while (ft_oless(a, a.tab[i]) != l)
		i++;
	re = (i > a.size / 2) ? 1 : -1;
	return (re);
}

void	put_back(t_stack *a, t_stack *b)
{
	int d;
	int t;
	int m;

	while (b->size)
	{
		d = ft_direction(*b, b->size - 1);
		t = 0;
		m = 0;
		while (ft_oless(*b, b->tab[b->size - 1]) != b->size - 1)
		{
			if (t == 0 && ft_oless(*b, b->tab[b->size - 1]) == b->size - 2)
			{
				ft_ppush(b, a, 'a');
				t = 1;
			}
			else if (d == 1)
				ft_prot(b, 'b');
			else
				ft_prvrot(b, 'b');
		}
		ft_ppush(b, a, 'a');
		if (t == 1)
			ft_psswap(a, 'a');
	}
}

void	order_two(t_stack *a, t_stack *b, int j)
{
	int k;
	int p[3];

	k = MIN((a->size - j) / 4, 40);
	if (a->size - j - k > 3)
		k--;
	p[0] = j + k + b->size;
	p[1] = j + b->size;
	while (j > 0 || k > -1)
	{
		while (ft_less(*a, *b, a->tab[a->size - 1]) > p[0])
			ft_prot(a, 'a');
		ft_ppush(a, b, 'b');
		if (ft_less(*a, *b, b->tab[b->size - 1]) < p[1])
		{
			j--;
			if ((j > 0 || k > -1) && ft_less(*a, *b,
						a->tab[a->size - 1]) > p[0])
				ft_protb(a, b);
			else
				ft_prot(b, 'b');
		}
		else
			k--;
	}
}

void	order_one_helper(t_stack *a, t_stack *b, int d, int p)
{
	int q;

	if (b->size)
		q = b->tab[b->size - 1];
	while (ft_less(*a, *b, a->tab[a->size - 1]) > p)
		d == 1 ? ft_prot(a, 'a') : ft_prvrot(a, 'a');
	ft_ppush(a, b, 'b');
	(b->size > 1 && b->tab[b->size - 2] != q &&
		b->tab[b->size - 1] > b->tab[b->size - 2]) ? ft_psswap(b, 'b') : 0;
}

void	order_one(t_stack *a, t_stack *b)
{
	int j;
	int p;
	int d;

	while (a->size > 3)
	{
		j = MIN(a->size / 4, 40);
		if (a->size - j > 50)
			order_two(a, b, j);
		else
		{
			while (a->size - j < 3)
				j--;
			d = direction(*a, j);
			p = j + b->size;
			while (j-- > -1)
				order_one_helper(a, b, d, p);
		}
	}
	sort_three(a);
	put_back(a, b);
}
