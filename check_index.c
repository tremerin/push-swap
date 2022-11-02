/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:15:19 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/09/15 18:15:21 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Comprueba si la pila A esta ordenada */
int	is_sorted(t_data *dat)
{
	int		i;

	i = 0;
	while (i < (dat->len_a - 1))
	{
		if (dat->array_a[i].index > dat->array_a[i + 1].index)
			return (0);
		i++;
	}
	return (1);
}

/* Calcula posición del mayor indice */
int	mayor_index_pos_a(t_data *dat)
{
	int		pos;
	int		mayor;
	int		i;

	pos = 0;
	i = 0;
	mayor = dat->array_a[pos].index;
	while (i < dat->len_a)
	{
		if (mayor < dat->array_a[i].index)
		{
			mayor = dat->array_a[i].index;
			pos = i;
		}
		i++;
	}
	return (pos);
}

/* Calcula el valor absoluto de un numero */
int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}
