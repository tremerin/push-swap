/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:51:27 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/09/13 17:51:29 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Ordena un array */
void static	sort_array(int *array, int len)
{
	int		i;
	int		j;
	int		aux;

	i = 0;
	while (i < len)
	{
		aux = array[i];
		j = i;
		while (j < len)
		{
			if (aux > array[j])
			{
				aux = array[j];
				array[j] = array[i];
				array[i] = aux;
			}
			j++;
		}
		i++;
	}
}

void static	write_index(t_data *dat, int *sorted)
{
	int		i;
	int		j;
	int		aux;
	int		index;

	i = 0;
	index = 1;
	while (i < dat->len_a)
	{
		aux = sorted[i];
		j = 0;
		while (j < dat->len_a)
		{
			if (aux == dat->array_a[j].value)
			{
				dat->array_a[j].index = index;
				index++;
			}
			j++;
		}
		i++;
	}
}

/* Asigna un indice a cada numero del array */
void	assing_index(t_data *dat)
{
	int	*sorted;
	int	i;

	i = 0;
	sorted = malloc(sizeof(int) * dat->len_a);
	while (i < dat->len_a)
	{
		sorted[i] = dat->array_a[i].value;
		i++;
	}
	sort_array(sorted, dat->len_a);
	write_index(dat, sorted);
	free(sorted);
}
