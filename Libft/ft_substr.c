/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:48:31 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/04/26 17:48:33 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			s_end;
	char			*result;
	unsigned int	i;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len < ft_strlen(s))
		s_end = start + len;
	else
		s_end = ft_strlen(s);
	result = malloc(sizeof(char) * (s_end - start + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (start < s_end)
	{
		result[i] = s[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}
