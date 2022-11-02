/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:49:19 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/09/22 18:49:22 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Busca la pareja de cada elemento en la pila B */
static void	find_couple(t_data *dat, int i)
{
	if (dat->array_b[i].index > mayor_a(dat))
		dat->array_b[i].a_index = minor_a(dat);
	else
		dat->array_b[i].a_index = next_mayor_a(dat, i);
}

/* Calcula el verdadero coste segun el signo de los costes de A y B */
static void	true_cost(t_data *dat, int pos)
{
	int		cost_a;
	int		cost_b;

	cost_a = ft_abs(dat->array_b[pos].cost_a);
	cost_b = ft_abs(dat->array_b[pos].cost_b);
	if ((dat->array_b[pos].cost_a > 0 && dat->array_b[pos].cost_b > 0)
		|| (dat->array_b[pos].cost_a < 0 && dat->array_b[pos].cost_b < 0))
	{
		if (cost_a > cost_b)
			dat->array_b[pos].cost_ab = cost_a;
		else
			dat->array_b[pos].cost_ab = cost_b;
	}
	else
		dat->array_b[pos].cost_ab = cost_a + cost_b;
}

/* Calcula y almacena el coste para mover la pareja a la posicies A0 B0 */
static void	calculate_cost(t_data *dat, int pos)
{
	if (dat->array_b[pos].a_pos > dat->len_a - dat->array_b[pos].a_pos)
		dat->array_b[pos].cost_a = (dat->len_a - dat->array_b[pos].a_pos) * -1;
	else
		dat->array_b[pos].cost_a = dat->array_b[pos].a_pos;
	if (dat->array_b[pos].b_pos > dat->len_b - dat->array_b[pos].b_pos)
		dat->array_b[pos].cost_b = (dat->len_b - dat->array_b[pos].b_pos) * -1;
	else
		dat->array_b[pos].cost_b = dat->array_b[pos].b_pos;
	true_cost(dat, pos);
}

/* Almacena en best_pos el indice del elemnto en B con el menor coste AB */
static void	best_cost(t_data *dat)
{
	int		i;
	int		cost;

	i = 0;
	dat->best_pos = 0;
	cost = dat->array_b[0].cost_ab;
	while (i < dat->len_b)
	{
		if (cost > dat->array_b[i].cost_ab)
		{
			cost = dat->array_b[i].cost_ab;
			dat->best_pos = i;
		}
		i++;
	}
	dat->move_a = dat->array_b[dat->best_pos].cost_a;
	dat->move_b = dat->array_b[dat->best_pos].cost_b;
}

/* Recorre los elementos de B y busca su pareja en A y el costa para unirlos,
luego une la pareja con menor coste */
void	best_move(t_data *dat)
{
	int		i;

	i = 0;
	while (i < dat->len_b)
	{
		find_couple(dat, i);
		find_couple_pos(dat, i);
		calculate_cost(dat, i);
		i++;
	}
	best_cost(dat);
	make_move(dat);
}
