/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:24:11 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/09/13 19:24:16 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pa: Toma el primer elemento en la parte superior de B y lo pone en A.
No hace nada si B está vacío. */
void	pa(t_data *dat)
{
	t_stack	aux;

	if (dat->len_b > 0)
	{
		aux = dat->array_b[0];
		pos_up(dat->array_b, dat->len_b);
		dat->len_b--;
		dat->len_a++;
		pos_down(dat->array_a, dat->len_a);
		dat->array_a[0] = aux;
		dat->movements++;
		write(1, "pa\n", 3);
	}
}

/* pb: Toma el primer elemento en la parte superior de A y lo pone en B.
No hace nada si A está vacío. */
void	pb(t_data *dat)
{
	t_stack	aux;

	if (dat->len_a > 0)
	{
		aux = dat->array_a[0];
		pos_up(dat->array_a, dat->len_a);
		dat->len_a--;
		dat->len_b++;
		pos_down(dat->array_b, dat->len_b);
		dat->array_b[0] = aux;
		dat->movements++;
		write(1, "pb\n", 3);
	}
}
