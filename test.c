/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:36:01 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/13 21:21:50 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void		process_buffer(char *buffer, char *line);
static char		*ft_strjoin(char *line, char *buffer);
static bool		find_new_line(char *line);
static size_t	ft_strlen_new_line(const char *s);
static void		copy_and_erase(char *dest, char *src, size_t n);

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	printf("Buffer size: %i\n", BUFFER_SIZE);
	buffer[BUFFER_SIZE] = '\0';
	line = malloc(sizeof(char));
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	process_buffer(buffer, line);
	if (line[ft_strlen_new_line(line)] == '\n')
	{
		printf("Found new line 1\n");
		return (line);
	}
	printf("Didn't find new line 1\n");
	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, (void *) buffer, BUFFER_SIZE);
		printf("Read %li bytes\n", bytes_read);
		if (bytes_read < 0)
			return (NULL);
		process_buffer(buffer, line);
		if (find_new_line(line))
		{
			printf("Found new line 2\n");
			return (line);
		}
		printf("Didn't find new line 2\n");
	}
	return (line);
}

static void	process_buffer(char *buffer, char *line)
{
	int		i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] != 0)
		{
			line = ft_strjoin(line, &buffer[i]);
			return ;
		}
		i++;
	}
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
		return (NULL);
	copy_and_erase(temp, line, line_len);
	copy_and_erase(&temp[line_len], buffer, buffer_len);
	temp[line_len + buffer_len] = '\0';
	free(line);
	return (temp);
}

static bool	find_new_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '\n')
			return (true);
		i++;
	}
	return (false);
}

static size_t	ft_strlen_new_line(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != '\n')
		len++;
	printf("Lenth is %li\n", len);
	return (len);
}

static void	copy_and_erase(char *dest, char *src, size_t n)
{
	size_t	i;

	if (n > 0)
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
