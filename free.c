/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:49:12 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/10/03 18:49:14 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Libera las posiciones de memoria */
void	free_all(t_data *dat)
{
	int		i;

	i = dat->len_a - 1;
	while (i >= dat->len_a)
	{
		free(&dat->array_a[i]);
		i--;
	}
	i = dat->len_a - 1;
	while (i >= dat->len_a)
	{
		free(&dat->array_b[i]);
		i--;
	}
	free_nums(dat);
}

void	free_nums(t_data *dat)
{
	int		i;

	i = dat->len_a - 1;
	while (i >= dat->len_a)
	{
		free(&dat->nums[i]);
		i--;
	}
}

void	error_exit(t_data *dat)
{
	write(2, "Error\n", 6);
	free_nums(dat);
	exit(1);
}

void	free_tnb(t_data *dat)
{
	int		i;

	i = dat->len_a;
	while (i >= 0)
	{
		free(dat->tnb[i]);
		i--;
	}
	free(dat->tnb);
}
