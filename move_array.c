/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:30:25 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/09/13 19:30:27 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pos_up(t_stack *array, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		array[i] = array[i + 1];
		i++;
	}
}

void	pos_down(t_stack *array, int len)
{
	int		i;

	i = len;
	while (i > 0)
	{
		array[i] = array[i - 1];
		i--;
	}
}
