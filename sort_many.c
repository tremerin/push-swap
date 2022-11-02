/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:19:09 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/09/20 17:19:13 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calcula la media de los indices de B*/
static void	average(t_data *dat)
{
	dat->average = dat->len_a / 2;
	if (dat->len_a % 2 != 0)
		dat->average++;
}

static void	move_to_b(t_data *dat)
{
	if (dat->array_a[0].index <= dat->average)
	{
		pb(dat);
	}
	else if (dat->len_b >= dat->average)
		pb(dat);
	else
	{
		ra(dat);
	}
}

static void	move_to_a(t_data *dat)
{
	while (dat->len_b > 0)
	{
		best_move(dat);
	}
}

void	sort_many(t_data *dat)
{
	average(dat);
	while (dat->len_a > 3)
		move_to_b(dat);
	just_three(dat);
	move_to_a(dat);
	if (!is_sorted(dat))
		make_move_three(dat);
}
