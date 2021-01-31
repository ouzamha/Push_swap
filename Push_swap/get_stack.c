/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 05:02:11 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/09/17 16:30:07 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_newatoi(char *str)
{
	int				i;
	int				j;
	int				s;

	i = 0;
	j = 0;
	s = 1;
	if (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			s = -1;
		j++;
	}
	while (str[j])
	{
		i = i * 10 + (str[j] - '0');
		j++;
	}
	return (i * s);
}

void	check_dig(char *str, int **tab)
{
	int j;

	j = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		str++;
		if (*str == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			free(*tab);
			exit(0);
		}
	}
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			free(*tab);
			exit(0);
		}
		str++;
	}
}

int		check_string(char *str, int **tab)
{
	size_t	l;

	l = ft_strlen(str);
	check_dig(str, tab);
	if (l > 11 || (l == 11 && str[0] != '-'))
	{
		ft_putstr_fd("Error\n", 2);
		free(*tab);
		exit(0);
	}
	else if (str[0] == '-' && l == 11 && ft_strcmp("2147483648", str + 1) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		free(*tab);
		exit(0);
	}
	else if (l == 10 && ft_strcmp("2147483647", str) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		free(*tab);
		exit(0);
	}
	else
		return (ft_newatoi(str));
}
