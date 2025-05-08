/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:36:01 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/08 11:58:56 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	char		*temp;
	size_t		bytes_read;
	size_t		len;
	size_t		nline;


	buffer = malloc (BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, (void *) buffer, BUFFER_SIZE);
		len = ft_strlen(line);
		if (len > 0)
		{
			temp = ft_memmove(temp, line, len);
			free(line);
			line = NULL;
			line = malloc ((len + bytes_read + 1) * sizeof(char));
			if (line == NULL)
				return (NULL);
			ft_memmove(line, temp, len);
		}
		ft_memmove(&line[len], buffer, bytes_read);
		free(buffer);
		buffer = NULL;
		len = ft_strlen(line);
		nline = find_new_line(line);
		if (nline < len)
			break;
	}
	ft_putstr(line);
	ft_memmove(line, &line[nline + 1], len - nline);
	ft_bzero(&line[len - nline], nline);
	return (line);
}

size_t	find_new_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	ft_putstr(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	if (s[i] == '\n')
	{
		write(1, "\n", 1);
	}
}

char	*ft_memmove(char *dest, char *src, size_t n)
{
	size_t	i;

	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}


void	ft_bzero(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
	return ;
}
