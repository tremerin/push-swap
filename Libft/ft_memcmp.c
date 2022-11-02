/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:34:28 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/04/22 19:34:32 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			index;
	unsigned char	*string1;
	unsigned char	*string2;

	index = 0;
	string1 = (unsigned char *)str1;
	string2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while (index < n)
	{
		if (string1[index] != string2[index])
			return (string1[index] - string2[index]);
		index++;
	}
	return (0);
}
