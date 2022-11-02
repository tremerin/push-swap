/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:20:13 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/09/11 19:20:16 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Retorna 1 si algun numero se repite */
static int	repeated_nums(t_data *dat)
{
	int		i;
	int		j;
	int		num;

	i = 0;
	while (i < dat->len_a)
	{
		num = dat->nums[i];
		j = i + 1;
		while (j < dat->len_a)
		{
			if (num == dat->nums[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/* Crea la data una vez validados los argumentos y comprabado si hay numeros
reptetidos */
void	create_data(t_data *dat)
{
	int		i;

	if (repeated_nums(dat))
		error_exit(dat);
	dat->array_a = ft_calloc(dat->len_a, sizeof(t_stack));
	dat->array_b = ft_calloc(dat->len_a, sizeof(t_stack));
	dat->len_b = 0;
	dat->movements = 0;
	i = 0;
	while (i < dat->len_a)
	{
		dat->array_a[i].value = dat->nums[i];
		i++;
	}
	assing_index(dat);
}
