/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:36:18 by akolupae          #+#    #+#             */
/*   Updated: 2025/05/01 16:36:20 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_new_line(const char *s)
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

void	ft_copy_and_erase(char *dest, char *src, size_t n)
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
