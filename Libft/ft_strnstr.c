/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:07:57 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/04/23 19:08:00 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*src;
	char			*find;

	i = 0;
	j = 0;
	src = (char *)str;
	find = (char *)to_find;
	if (find[0] == '\0')
		return (src);
	while (src[i] != '\0' && i < len)
	{
		j = 0;
		while (src[i + j] != '\0' && src[i + j] == find[j] && (i + j) < len)
		{
			if (to_find[j + 1] == '\0')
				return (&src[i]);
			j++;
		}
		i++;
	}
	return (0);
}
