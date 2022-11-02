/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:32:51 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/05/02 17:32:54 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getstart(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	ft_getend(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*newstr;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = ft_getstart(s1, set);
	end = ft_getend(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	newstr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, s1 + start, end - start + 1);
	return (newstr);
}

/*
static int	strlentrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				len--;
			j++;
		}
		i++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	if (set[0] == '\0')
		return (ft_strdup(s1));
	len = strlentrim(s1, set);
	str = (char *)malloc(sizeof(char) * len);
	i = 0;
	len = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j] && set[j] != s1[i])
		{
			if (set[j + 1] == '\0')
				str[len++] = s1[i];
			j++;
		}
		i++;
	}
	str[len] = '\0';
	return (str);
}
*/
