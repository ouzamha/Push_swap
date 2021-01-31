/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 23:54:17 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/08/15 05:37:30 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_true(unsigned char c1, unsigned char c2)
{
	if (c1 == c2 && c1 != '\0')
		return (1);
	else
		return (0);
}

int		strc(char *s1, char *s2)
{
	int			i;

	i = 0;
	while (ft_true((unsigned char)s1[i], (unsigned char)s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
