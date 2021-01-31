/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:42:38 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/09/17 16:04:31 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"
# define MIN(a,b) ((a) > (b) ? (b) : (a))

typedef struct		s_stack
{
	int		*tab;
	int		size;
}					t_stack;

int					fcheck(t_stack s);
void				sort_three(t_stack *a);
int					finalcheck(t_stack s, t_stack b);
int					get_line(char *line, t_stack *a, t_stack *b);
void				get_instr(t_stack *a, t_stack *b);
int					ft_newatoi(char *str);
void				check_dig(char *str, int **tab);
int					check_string(char *str, int **tab);
t_stack				get_stack(char **argv, int argc);
t_stack				get_stack_helper(char **argv, int argc);
int					c_d(char **s, int gc);
int					ft_less(t_stack a, t_stack b, int elm);
int					ft_oless(t_stack b, int elm);
int					direction(t_stack a, int l);
int					ft_direction(t_stack a, int l);
void				put_back(t_stack *a, t_stack *b);
void				order_two(t_stack *a, t_stack *b, int j);
void				order_one_helper(t_stack *a, t_stack *b, int d, int p);
void				order_one(t_stack *a, t_stack *b);
void				ft_sswap(t_stack *a, t_stack *b, char i);
void				ft_push(t_stack *a, t_stack *b, char i);
void				ft_rot(t_stack *a, t_stack *b, char j);
void				ft_rvrot(t_stack *a, t_stack *b, char j);
void				ft_psswap(t_stack *s, char c);
void				ft_ppush(t_stack *f, t_stack *d, char c);
void				ft_prot(t_stack *s, char c);
void				ft_prvrot(t_stack *s, char c);
int					ft_true(unsigned char c1, unsigned char c2);
int					strc(char *s1, char *s2);
void				free_error(t_stack *a, t_stack *b);
void				ft_protb(t_stack *s, t_stack *h);
char				**get_digits(char **argv, int argc, int i);
#endif
