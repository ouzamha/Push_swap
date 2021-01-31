/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stackk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:46:56 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/09/17 16:56:24 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack		get_stack_helper(char **argv, int argc)
{
	t_stack a;
	int		i[2];
	int		c;

	a.size = argc;
	if (!(a.tab = malloc(sizeof(int) * a.size)))
		exit(1);
	i[0] = 0;
	i[1] = a.size;
	while (--(i[1]) >= 0)
	{
		c = a.size - 1;
		a.tab[i[1]] = check_string(argv[(i[0])++], &(a.tab));
		while (c > i[1])
		{
			if (a.tab[c] == a.tab[i[1]])
			{
				ft_putstr_fd("Error\n", 2);
				free(a.tab);
				exit(0);
			}
			c--;
		}
	}
	return (a);
}

t_stack		get_stack(char **argv, int argc)
{
	t_stack	stack;
	char	**digits;
	int		k;
	int		i;

	argc == 1 ? exit(0) : 0;
	k = 0;
	i = c_d(argv, argc);
	if (i == 0)
		exit(0);
	digits = get_digits(argv, argc, i);
	stack = get_stack_helper(digits, i);
	while (digits[k])
	{
		free(digits[k]);
		k++;
	}
	free(digits);
	return (stack);
}
