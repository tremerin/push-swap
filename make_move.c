/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:28:37 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/09/23 20:28:41 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Ejecuta movimientos de A o B por separado */
void	make_move_two(t_data *dat)
{
	while (dat->move_a > 0)
	{
		ra(dat);
		dat->move_a--;
	}
	while (dat->move_a < 0)
	{
		rra(dat);
		dat->move_a++;
	}
	while (dat->move_b > 0)
	{
		rb(dat);
		dat->move_b--;
	}
	while (dat->move_b < 0)
	{
		rrb(dat);
		dat->move_b++;
	}
}

/* Rota los elementos de A hasta dejar el mayor indice en su sitio */
void	make_move_three(t_data *dat)
{
	int		pos;
	int		i;

	i = 0;
	while (i < dat->len_a)
	{
		if (dat->array_a[i].index == dat->len_a)
			pos = i + 1;
		i++;
	}
	if (pos > dat->len_a - pos)
		dat->move_a = (dat->len_a - pos) * -1;
	else
		dat->move_a = pos;
	make_move_two(dat);
}

/* Ejecuta los movimientos conjuntos de A y B */
void	make_move(t_data *dat)
{
	while (dat->move_a != 0 || dat->move_b != 0)
	{
		while (dat->move_a > 0 && dat->move_b > 0)
		{
			rr(dat);
			dat->move_a--;
			dat->move_b--;
		}
		while (dat->move_a < 0 && dat->move_b < 0)
		{
			rrr(dat);
			dat->move_a++;
			dat->move_b++;
		}
		make_move_two(dat);
	}
	pa(dat);
}
