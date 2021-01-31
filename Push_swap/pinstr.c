/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pinstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 01:04:22 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/09/14 16:22:59 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_psswap(t_stack *s, char c)
{
	if (s->size > 1)
	{
		ft_swap(s->tab + s->size - 2, s->tab + s->size - 1);
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	ft_ppush(t_stack *f, t_stack *d, char c)
{
	if (f->size)
	{
		d->tab[(d->size)++] = f->tab[--(f->size)];
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	ft_protb(t_stack *s, t_stack *h)
{
	int temp;
	int i;

	i = -1;
	temp = s->tab[s->size - 1];
	while (++i < s->size)
		ft_swap(s->tab + i, &temp);
	i = -1;
	temp = h->tab[h->size - 1];
	while (++i < h->size)
		ft_swap(h->tab + i, &temp);
	write(1, "rr\n", 3);
}

void	ft_prot(t_stack *s, char c)
{
	int temp;
	int i;

	i = -1;
	temp = s->tab[s->size - 1];
	while (++i < s->size)
		ft_swap(s->tab + i, &temp);
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	ft_prvrot(t_stack *s, char c)
{
	int temp;
	int i;

	temp = s->tab[0];
	i = s->size;
	while (--i >= 0)
		ft_swap(s->tab + i, &temp);
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}
