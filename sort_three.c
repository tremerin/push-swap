/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:05:00 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/09/16 19:05:02 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	just_three(t_data *dat)
{
	if (!is_sorted(dat))
	{
		if (mayor_index_pos_a(dat) == 0)
			ra(dat);
		else if (mayor_index_pos_a(dat) == 1)
			rra(dat);
		else if (mayor_index_pos_a(dat) == 2)
			sa(dat);
		just_three(dat);
	}
}

void	sort_three(t_data *dat)
{
	if (dat->len_a == 1)
		if (is_sorted(dat))
			free_all(dat);
	if (dat->len_a == 2)
	{
		if (!is_sorted(dat))
			sa(dat);
		free_all(dat);
	}
	if (dat->len_a == 3)
	{
		just_three(dat);
		free_all(dat);
	}
}
