/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:45:31 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/14 16:29:17 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			write(2, "Open error", 10);
			return (-1);
		}
	}
	printf("Buffer size: %i\n", BUFFER_SIZE);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line != NULL)
		{
			free(line);
			line = NULL;
		}
		else
			break ;
	}
	close(fd);
	return (0);
}
