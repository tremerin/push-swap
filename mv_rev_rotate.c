/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:13:53 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/09/14 19:13:55 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rra: desplaza hacia abajo una posición todos los elementos de la pila A.
El último elemento se convierte en el primero. */
void	rra(t_data *dat)
{
	t_stack	aux;

	if (dat->len_a > 1)
	{
		aux = dat->array_a[dat->len_a - 1];
		pos_down(dat->array_a, dat->len_a);
		dat->array_a[0] = aux;
		dat->movements++;
		write(1, "rra\n", 4);
	}
}

/* rrb: desplaza hacia abajo una posición todos los elementos de la pila B.
El último elemento se convierte en el primero. */
void	rrb(t_data *dat)
{
	t_stack	aux;

	if (dat->len_b > 1)
	{
		aux = dat->array_b[dat->len_b - 1];
		pos_down(dat->array_b, dat->len_b);
		dat->array_b[0] = aux;
		dat->movements++;
		write(1, "rrb\n", 4);
	}
}

/* rrr: rra y rrb al mismo tiempo. */
void	rrr(t_data *dat)
{
	t_stack	aux;

	if (dat->len_a > 1)
	{
		aux = dat->array_a[dat->len_a - 1];
		pos_down(dat->array_a, dat->len_a);
		dat->array_a[0] = aux;
	}
	if (dat->len_b > 1)
	{
		aux = dat->array_b[dat->len_b - 1];
		pos_down(dat->array_b, dat->len_b);
		dat->array_b[0] = aux;
	}
	dat->movements++;
	write(1, "rrr\n", 4);
}
