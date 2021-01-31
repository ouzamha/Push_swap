/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_digits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:34:58 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/09/17 16:57:32 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		c_d(char **gv, int gc)
{
	int i;
	int b[2];
	int k;

	i = 1;
	b[1] = 0;
	k = 0;
	while (i < gc)
	{
		b[0] = 1;
		k = 0;
		while (gv[i][k])
		{
			if (gv[i][k] == ' ')
				b[0] = 1;
			if (gv[i][k] != ' ' && b[0] == 1)
			{
				b[0] = 0;
				b[1]++;
			}
			k++;
		}
		i++;
	}
	return (b[1]);
}

void	get_digits_helper(char *gv, char **re, int *j)
{
	int		k;
	int		t;

	k = 0;
	while (*gv)
	{
		if (*gv == ' ')
			gv++;
		else
		{
			t = 0;
			while (gv[t] && gv[t] != ' ')
				t++;
			if (!(re[*j] = ft_strsub(gv, 0, t)))
			{
				t = -1;
				while (++t < *j)
					free(re[t]);
				free(re);
				exit(1);
			}
			(*j)++;
			gv = gv + t;
		}
	}
}

char	**get_digits(char **gv, int gc, int c)
{
	char	**re;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (!(re = (char **)malloc(sizeof(char *) * (c + 1))))
		exit(1);
	while (i < gc)
	{
		get_digits_helper(gv[i], re, &j);
		i++;
	}
	re[j] = NULL;
	return (re);
}
