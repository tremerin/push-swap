/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:58:34 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/09/14 18:58:36 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ra: Desplaza todos los elementos de la pila A una posición hacia arriba.
El primer elemento se convierte en el último. */
void	ra(t_data *dat)
{
	t_stack	aux;

	if (dat->len_a > 1)
	{
		aux = dat->array_a[0];
		pos_up(dat->array_a, dat->len_a);
		dat->array_a[dat->len_a - 1] = aux;
		dat->movements++;
		write(1, "ra\n", 3);
	}
}

/* rb: Desplaza todos los elementos de la pila B una posición hacia arriba.
El primer elemento se convierte en el último. */
void	rb(t_data *dat)
{
	t_stack	aux;

	if (dat->len_b > 1)
	{
		aux = dat->array_b[0];
		pos_up(dat->array_b, dat->len_b);
		dat->array_b[dat->len_b - 1] = aux;
		dat->movements++;
		write(1, "rb\n", 3);
	}
}

/* rr: ra y rb al mismo tiempo. */
void	rr(t_data *dat)
{
	t_stack	aux;

	if (dat->len_a > 1)
	{
		aux = dat->array_a[0];
		pos_up(dat->array_a, dat->len_a);
		dat->array_a[dat->len_a - 1] = aux;
	}
	if (dat->len_b > 1)
	{
		aux = dat->array_b[0];
		pos_up(dat->array_b, dat->len_b);
		dat->array_b[dat->len_b - 1] = aux;
	}
	dat->movements++;
	write(1, "rr\n", 3);
}
