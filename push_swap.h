/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:43:19 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/09/06 17:43:25 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* stack */
typedef struct s_stack {
	int			value;
	int			index;
	int			a_pos;
	int			b_pos;
	int			a_index;
	int			cost_a;
	int			cost_b;
	int			cost_ab;
}	t_stack;

/* data */
typedef struct s_data {
	t_stack		*array_a;
	t_stack		*array_b;
	char		**tnb;
	int			*nums;
	int			len_a;
	int			len_b;
	int			average;
	int			best_pos;
	int			move_a;
	int			move_b;
	int			movements;
}	t_data;

void		validate_argument(t_data *dat, char **argv);
void		validate_arguments(t_data *dat, int argc, char **argv);
void		create_data(t_data *dat);
void		free_all(t_data *dat);
void		free_nums(t_data *dat);
void		free_tnb(t_data *dat);
void		error_exit(t_data *dat);

/* moves */
void		pos_up(t_stack *array, int len);
void		pos_down(t_stack *array, int len);
void		pb(t_data *dat);
void		pa(t_data *dat);
void		sa(t_data *dat);
void		sb(t_data *dat);
void		ss(t_data *dat);
void		ra(t_data *dat);
void		rb(t_data *dat);
void		rr(t_data *dat);
void		rra(t_data *dat);
void		rrb(t_data *dat);
void		rrr(t_data *dat);

/* sort */
void		sort_three(t_data *dat);
void		sort_many(t_data *dat);
void		just_three(t_data *dat);
void		best_move(t_data *dat);
int			mayor_a(t_data *dat);
int			minor_a(t_data *dat);
int			next_mayor_a(t_data *dat, int j);
void		find_couple_pos(t_data *dat, int i);
void		assing_index(t_data *dat);
int			mayor_index_pos_a(t_data *dat);
int			index_pos(t_data *dat, int index, char array);
int			is_sorted(t_data *dat);
void		make_move(t_data *dat);
void		make_move_three(t_data *dat);

/* utils */
int			count_words(const char *str, char c);
long long	ft_atoli(const char *str);
int			ft_abs(int num);

#endif
