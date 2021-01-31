/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 05:10:52 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/09/14 16:36:31 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sswap(t_stack *a, t_stack *b, char i)
{
	t_stack	*s;

	if (i == 'a')
		s = a;
	else if (i == 'b')
		s = b;
	else
	{
		s = a;
		ft_sswap(a, b, 'b');
	}
	if (s->size > 1)
		ft_swap(s->tab + s->size - 2, s->tab + s->size - 1);
}

void	ft_push(t_stack *a, t_stack *b, char i)
{
	t_stack *f;
	t_stack *d;

	f = b;
	d = a;
	if (i == 'b')
	{
		f = a;
		d = b;
	}
	if (f->size)
		d->tab[(d->size)++] = f->tab[--(f->size)];
}

void	ft_rot(t_stack *a, t_stack *b, char j)
{
	int		temp;
	t_stack	*s;
	int		i;

	i = -1;
	s = a;
	if (j == 'b')
		s = b;
	if (j == 'r')
	{
		ft_rot(a, b, 'a');
		ft_rot(a, b, 'b');
	}
	else
	{
		temp = s->tab[s->size - 1];
		while (++i < s->size)
			ft_swap(s->tab + i, &temp);
	}
}

void	ft_rvrot(t_stack *a, t_stack *b, char j)
{
	t_stack	*s;
	int		temp;
	int		i;

	s = a;
	if (j == 'b')
		s = b;
	if (j == 'r')
	{
		ft_rvrot(a, b, 'a');
		ft_rvrot(a, b, 'b');
	}
	temp = s->tab[0];
	i = s->size;
	while (--i >= 0)
		ft_swap(s->tab + i, &temp);
}
