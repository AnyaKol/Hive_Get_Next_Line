/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:36:01 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/14 16:53:23 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char		*process_buffer(char *buffer, char *line);
static char		*ft_strjoin(char *line, char *buffer);
static size_t	ft_strlen_new_line(const char *s);
static void		copy_and_erase(char *dest, char *src, size_t n);

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	buffer[BUFFER_SIZE] = '\0';
	line = NULL;
	line = process_buffer(buffer, line);
	if (line != NULL)
	{
		if (line[ft_strlen_new_line(line) - 1] == '\n')
			return (line);
	}
	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, (void *) buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(line);
			line = NULL;
			return (NULL);
		}
		line = process_buffer(buffer, line);
		if (line != NULL)
		{
			if (line[ft_strlen_new_line(line) - 1] == '\n')
				return (line);
		}
	}
	return (line);
}

static char	*process_buffer(char *buffer, char *line)
{
	int		i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] != 0)
		{
			line = ft_strjoin(line, &buffer[i]);
			return (line);
		}
		i++;
	}
	return (line);
}

static char	*ft_strjoin(char *line, char *buffer)
{
	size_t	buffer_len;
	size_t	line_len;
	char	*temp;

	buffer_len = ft_strlen_new_line(buffer);
	line_len = ft_strlen_new_line(line);
	temp = malloc(sizeof(char) * (line_len + buffer_len + 1));
	if (temp == NULL)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	copy_and_erase(temp, line, line_len);
	copy_and_erase(&temp[line_len], buffer, buffer_len);
	temp[line_len + buffer_len] = '\0';
	free(line);
	line = NULL;
	return (temp);
}

static size_t	ft_strlen_new_line(const char *s)
{
	size_t	len;

	len = 0;
	if (s != NULL)
	{
		while (s[len] != '\0' && s[len] != '\n')
			len++;
		if (s[len] == '\n')
			len++;
	}
	return (len);
}

static void	copy_and_erase(char *dest, char *src, size_t n)
{
	size_t	i;

	if (n > 0 && src != NULL && dest != NULL)
	{
		i = 0;
		while (i < n)
		{
			dest[i] = src[i];
			src[i] = '\0';
			i++;
		}
	}
}
