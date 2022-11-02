/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:14:43 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/04/21 18:14:46 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*new;
	int		index;
	int		size;

	size = 0;
	while (src[size])
		++size;
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	index = 0;
	while (src[index] != '\0')
	{
		new[index] = src[index];
		index++;
	}
	new[index] = '\0';
	return (new);
}
