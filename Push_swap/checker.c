/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:41:59 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/09/14 15:16:12 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		finalcheck(t_stack s, t_stack b)
{
	int i;

	i = 0;
	if (b.size > 0)
	{
		ft_putstr("KO\n");
		return (0);
	}
	while (i < s.size - 1)
	{
		if (s.tab[i] < s.tab[i + 1])
		{
			ft_putstr("KO\n");
			return (0);
		}
		i++;
	}
	ft_putstr("OK\n");
	return (1);
}

int		get_line(char *line, t_stack *a, t_stack *b)
{
	int		cd;
	char	l;
	int		i;

	ft_bzero(line, 5);
	i = 0;
	while ((cd = read(0, &l, 1)) > 0)
	{
		if (l == '\n')
		{
			if (i < 5)
				line[i] = '\n';
			break ;
		}
		if (i < 5)
			line[i] = l;
		i++;
	}
	if (i >= 5)
		free_error(a, b);
	return (cd);
}

void	free_error(t_stack *a, t_stack *b)
{
	ft_putstr_fd("Error\n", 2);
	if (a && a->tab)
		free(a->tab);
	if (b && b->tab)
		free(b->tab);
	exit(0);
}

void	get_instr(t_stack *a, t_stack *b)
{
	char l[5];
	void (*pf)(t_stack *, t_stack *, char);

	ft_bzero(l, 5);
	while (get_line(l, a, b) || ft_strlen(l))
	{
		if (!strc(l, "rra\n") || !strc(l, "rrb\n") || !strc(l, "rrr\n"))
			pf = &ft_rvrot;
		else if (!strc(l, "sa\n") || !strc(l, "sb\n") || !strc(l, "ss\n"))
			pf = &ft_sswap;
		else if (!strc(l, "ra\n") || !strc(l, "rb\n") || !strc(l, "rr\n"))
			pf = &ft_rot;
		else if (!strc(l, "pa\n") || !strc(l, "pb\n"))
			pf = &ft_push;
		else
			free_error(a, b);
		(*pf)(a, b, l[ft_strlen(l) - 2]);
	}
}

int		main(int gc, char *gv[])
{
	t_stack a;
	t_stack b;

	a.tab = NULL;
	b.tab = NULL;
	a = get_stack(gv, gc);
	b.size = 0;
	if (a.size == 0 || !(b.tab = malloc(sizeof(int) * a.size)))
	{
		if (a.tab)
			free(a.tab);
		exit(0);
	}
	get_instr(&a, &b);
	finalcheck(a, b);
	free(a.tab);
	free(b.tab);
	return (0);
}
