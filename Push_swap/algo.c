/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 23:59:09 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/09/14 21:56:03 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		fcheck(t_stack s)
{
	int i;

	i = 0;
	while (i < s.size - 1)
	{
		if (s.tab[i] < s.tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_three(t_stack *a)
{
	if ((a->tab)[a->size - 1] < (a->tab)[a->size - 2] && fcheck(*a) == 0)
	{
		if ((a->tab)[a->size - 1] < (a->tab)[a->size - 3])
		{
			ft_psswap(a, 'a');
			sort_three(a);
		}
		else
			ft_prvrot(a, 'a');
	}
	if ((a->tab)[a->size - 1] > (a->tab)[a->size - 2])
	{
		if ((a->tab)[a->size - 2] > (a->tab)[a->size - 3])
		{
			ft_psswap(a, 'a');
			sort_three(a);
		}
		else
		{
			if ((a->tab)[a->size - 1] > (a->tab)[a->size - 3])
				ft_prot(a, 'a');
			else
				ft_psswap(a, 'a');
		}
	}
}
