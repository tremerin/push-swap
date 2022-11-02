/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:30:10 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/09/14 18:30:12 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa: Intercambia los primeros 2 elementos en la parte superior de la pila A.
No hace nada si solo hay uno o ninguno. */
void	sa(t_data *dat)
{
	t_stack	aux;

	if (dat->len_a > 1)
	{
		aux = dat->array_a[0];
		dat->array_a[0] = dat->array_a[1];
		dat->array_a[1] = aux;
		dat->movements++;
		write(1, "sa\n", 3);
	}
}

/* sb: Intercambia los primeros 2 elementos en la parte superior de la pila B.
No hace nada si solo hay uno o ninguno. */
void	sb(t_data *dat)
{
	t_stack	aux;

	if (dat->len_b > 1)
	{
		aux = dat->array_b[0];
		dat->array_b[0] = dat->array_b[1];
		dat->array_b[1] = aux;
		dat->movements++;
		write(1, "sb\n", 3);
	}
}

/* ss: sa y  sb al mismo tiempo. */
void	ss(t_data *dat)
{
	t_stack	aux;

	if (dat->len_a > 1)
	{
		aux = dat->array_a[0];
		dat->array_a[0] = dat->array_a[1];
		dat->array_a[1] = aux;
	}
	if (dat->len_b > 1)
	{
		aux = dat->array_b[0];
		dat->array_b[0] = dat->array_b[1];
		dat->array_b[1] = aux;
	}
	dat->movements++;
	write(1, "ss\n", 3);
}
