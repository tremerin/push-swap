/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:52:15 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/09/11 18:52:20 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data		dat;

	if (argc == 1)
		exit(0);
	if (argc == 2)
		validate_argument(&dat, argv);
	if (argc > 2)
		validate_arguments(&dat, argc, argv);
	create_data(&dat);
	if (dat.len_a <= 3)
		sort_three(&dat);
	else
	{
		if (!is_sorted(&dat))
			sort_many(&dat);
	}
	free_all(&dat);
	return (0);
}
