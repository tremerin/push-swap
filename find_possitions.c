/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_possitions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:34:32 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/09/24 19:34:34 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Devuelve el valor del mayor indice de A */
int	mayor_a(t_data *dat)
{
	int	mayor;
	int	i;

	i = 0;
	mayor = dat->array_a[0].index;
	while (i < dat->len_a)
	{
		if (dat->array_a[i].index > mayor)
			mayor = dat->array_a[i].index;
		i++;
	}
	return (mayor);
}

/* Devuelve el valor del menor indice de A */
int	minor_a(t_data *dat)
{
	int	minor;
	int	i;

	i = 0;
	minor = dat->array_a[0].index;
	while (i < dat->len_a)
	{
		if (dat->array_a[i].index < minor)
		{
			minor = dat->array_a[i].index;
		}
		i++;
	}
	return (minor);
}

/* Devuelve el valor del indice inmediatamente superior al indice de
la posicion que pasamos */
int	next_mayor_a(t_data *dat, int pos)
{
	int		next;
	int		i;

	next = mayor_a(dat);
	i = 0;
	while (i < dat->len_a)
	{
		if (dat->array_b[pos].index < dat->array_a[i].index
			&& dat->array_a[i].index < next)
			next = dat->array_a[i].index;
		i++;
	}
	return (next);
}

/* Devuelve la posicion de un indice */
int	index_pos(t_data *dat, int index, char array)
{
	int		i;

	i = 0;
	if (array == 'a')
	{
		while (i < dat->len_a)
		{
			if (dat->array_b[index].a_index == dat->array_a[i].index)
				return (i);
			i++;
		}
	}
	else
	{
		return (index);
	}
	return (-1);
}

/* Almacena las posiciones de la pareja */
void	find_couple_pos(t_data *dat, int i)
{
	dat->array_b[i].b_pos = index_pos(dat, i, 'b');
	dat->array_b[i].a_pos = index_pos(dat, i, 'a');
}
