# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 16:01:21 by ouzamhar          #+#    #+#              #
#    Updated: 2019/09/17 16:59:41 by ouzamhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

SRC = get_stack.c get_stackk.c get_digits.c

SRC1 = checker.c strc.c instr.c 

LIB = libft/libft.a

NAME2 = push_swap

SRC2 = algo.c pinstr.c order.c orderhelp.c push_swap.c 

OBJ = $(SRC:.c=.o)

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

all : $(NAME1) $(NAME2)

$(NAME1) : $(LIB) $(OBJ) $(OBJ1)
	gcc $(OBJ) $(OBJ1) -o $(NAME1) $(LIB)

$(NAME2) : $(LIB) $(OBJ) $(OBJ2)
	gcc $(OBJ) $(OBJ2) -o $(NAME2) $(LIB)

$(OBJ) : %.o : %.c checker.h libft/libft.h
	gcc  -Wall -Wextra -Werror -c $< -o $@ -I libft

$(OBJ1) : %.o : %.c checker.h libft/libft.h
	gcc -Wall -Wextra -Werror -c $< -o $@ -I libft

$(OBJ2) : %.o : %.c checker.h libft/libft.h
	gcc -Wall -Wextra -Werror -c $< -o $@ -I libft

$(LIB) : 
	make -C libft
clean :
	make clean -C libft
	rm -rf $(OBJ) $(OBJ2) $(OBJ1)
fclean : clean
	make fclean -C libft
	rm -rf $(NAME1) $(NAME2)
re : fclean all
