/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:45:31 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/15 14:20:27 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

void	print_line(int fd);

int	main(int argc, char **argv)
{
	int		fd_array[1024];
	int		i;

	printf("Buffer size: %i\n", BUFFER_SIZE);
	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			fd_array[i] = open(argv[i], O_RDONLY);
			printf("\nFD: %i\n", fd_array[i]);
			print_line(fd_array[i]);
			print_line(fd_array[i]);
			i++;
		}
		i = 1;
		while (i < argc)
		{
			printf("\nFD: %i\n", fd_array[i]);
			print_line(fd_array[i]);
			close(fd_array[i]);
			i++;
		}
	}
	return (0);
}

void	print_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	printf("%s", line);
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
}
