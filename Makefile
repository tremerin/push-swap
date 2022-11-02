# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 18:14:12 by fgalan-r          #+#    #+#              #
#    Updated: 2022/10/05 18:14:16 by fgalan-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
SRC			= assign_index.c \
			best_move.c \
			check_index.c \
			create_data.c \
			find_possitions.c \
			free.c \
			make_move.c \
			move_array.c \
			mv_push.c \
			mv_rev_rotate.c \
			mv_rotate.c \
			mv_swap.c \
			push_swap.c \
			sort_many.c \
			sort_three.c \
			utils.c \
			validate_arguments.c

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
LIBFT_PATH 	= ./Libft
OBJS		= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(OBJS) $(LIBFT_PATH)/libft.a -o $(NAME)

clean :
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean :
	make -C $(LIBFT_PATH) fclean
	$(RM) $(OBJS) $(NAME)

re : fclean all

