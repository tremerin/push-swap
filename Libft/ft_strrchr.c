/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:34:43 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/04/27 19:34:48 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	*str;

	str = (char *)s;
	index = ft_strlen(str);
	if ((char)c == '\0')
		return (str + index);
	while (index + 1 > 0)
	{
		if (str[index] == (char)c)
			return ((char *)&str[index]);
		index--;
	}
	return (NULL);
}
