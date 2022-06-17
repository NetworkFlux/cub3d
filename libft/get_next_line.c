/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:11:55 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/17 15:58:41 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

static char	*ft_clean(char *str)
{
	size_t	size;

	if (!str)
		return (NULL);
	size = ft_strlengnl(str);
	if (size > 0 && str[size - 1] == '\n')
		str[size - 1] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;
	ssize_t		size;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	result = ft_initialize(buffer);
	if (ft_end_of_line(result) == 1)
		return (ft_clean(result));
	size = read(fd, buffer, BUFFER_SIZE);
	if (size == 0 && result[0] != '\0')
		return (ft_clean(result));
	if (size <= 0)
	{
		free (result);
		return (NULL);
	}
	while (size > 0)
	{
		result = ft_straddback(result, buffer, size);
		if (ft_end_of_line(result) == 1)
			return (ft_clean(result));
		size = read(fd, buffer, BUFFER_SIZE);
	}
	return (ft_clean(result));
}
