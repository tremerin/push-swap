/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:13:05 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/09/11 19:13:07 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Retorna 1 si la cadena no tiene mas de un signo + o - */
static int	count_sign(char *str)
{
	int		signs;

	signs = 0;
	while (*str)
	{
		if (*str == '+' || *str == '-')
			signs++;
		str++;
	}
	if (signs > 1)
		return (0);
	return (1);
}

/* Retorna 1 si es un entero positivo o negativo */
static int	is_int(char *num)
{
	int		i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]) && num[i] != '-' && num[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

void	validate_argument(t_data *dat, char **argv)
{
	int				i;

	i = 0;
	dat->len_a = count_words(argv[1], ' ');
	dat->tnb = ft_split(argv[1], ' ');
	dat->nums = malloc(sizeof(int) * dat->len_a);
	while (i < dat->len_a)
	{
		if (!is_int(dat->tnb[i]) || !count_sign(dat->tnb[i]))
		{
			free_tnb(dat);
			error_exit(dat);
		}
		if (ft_atoli(dat->tnb[i]) > INT_MAX || ft_atoli(dat->tnb[i]) < INT_MIN)
		{
			free_tnb(dat);
			error_exit(dat);
		}
		else
			dat->nums[i] = ft_atoli(dat->tnb[i]);
		i++;
	}
	free_tnb(dat);
}

void	validate_arguments(t_data *dat, int argc, char **argv)
{
	int		i;

	i = 1;
	dat->len_a = argc -1;
	dat->nums = malloc(sizeof(int) * dat->len_a);
	if (dat->nums == NULL)
		exit(1);
	while (i <= dat->len_a)
	{
		if (!is_int(argv[i]) || !count_sign(argv[i]))
			error_exit(dat);
		if (ft_atoli(argv[i]) > INT_MAX || ft_atoli(argv[i]) < INT_MIN)
			error_exit(dat);
		else
			dat->nums[i -1] = ft_atoli(argv[i]);
		i++;
	}
}
