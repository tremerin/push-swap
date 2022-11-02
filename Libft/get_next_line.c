/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:41:30 by fgalan-r          #+#    #+#             */
/*   Updated: 2022/06/20 10:41:36 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cut(char *buffer)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new = malloc(sizeof(char) * (ft_strlen(buffer) - i) + 1);
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		new[j++] = buffer[i++];
	new[j] = '\0';
	free(buffer);
	return (new);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	line[i + 1] = '\0';
	line[i] = '\n';
	while (i >= 0)
	{
		line[i] = buffer[i];
		i--;
	}
	return (line);
}

static char	*ft_join(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	buffer = temp;
	return (buffer);
}

static char	*ft_read(int fd, char *buffer)
{
	int			nr_bytes;
	char		*buf;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	nr_bytes = 1;
	while (nr_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		nr_bytes = read(fd, buf, BUFFER_SIZE);
		if (nr_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[nr_bytes] = '\0';
		buffer = ft_join(buffer, buf);
		if (buffer[0] == '\0')
		{
			free(buffer);
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	char static	*buffer;

	if (fd < 0 || read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_cut(buffer);
	return (line);
}
