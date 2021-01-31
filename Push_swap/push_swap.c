/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 00:41:14 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/09/19 19:43:45 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int gc, char *gv[])
{
	t_stack a;
	t_stack b;

	a = get_stack(gv, gc);
	b.size = 0;
	if (!(b.tab = malloc(sizeof(int) * a.size)))
	{
		free(a.tab);
		exit(1);
	}
	if (fcheck(a) == 0)
	{
		if (a.size == 2)
			ft_psswap(&a, 'a');
		else
			order_one(&a, &b);
	}
	free(a.tab);
	free(b.tab);
	return (0);
}
