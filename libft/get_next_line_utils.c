/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:11:36 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/17 15:25:57 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlengnl(char *str)
{
	size_t	l;

	l = 1;
	while (str[l])
		l++;
	return (l);
}

void	ft_delbuffer(char *buffer, int l)
{
	while (buffer[l])
	{
		buffer[l] = '\0';
		l++;
	}
}

char	*ft_straddback(char *result, char *buffer, ssize_t size)
{
	char	*newresult;
	ssize_t	i;
	ssize_t	l;

	i = -1;
	newresult = malloc(sizeof(char) * (size + ft_strlengnl(result) + 1));
	if (!newresult)
	{
		free (result);
		return (NULL);
	}
	while (result[++i])
		newresult[i] = result[i];
	free (result);
	l = 0;
	while (buffer[l] && size - l > 0)
	{
		newresult[i + l] = buffer[l];
		l++;
	}
	if (size == l)
		ft_delbuffer(buffer, l);
	newresult[i + l] = '\0';
	return (newresult);
}

int	ft_end_of_line(char *str)
{
	while (*str)
	{
		if (*str == '\n')
		{
			str++;
			*str = '\0';
			return (1);
		}
		str++;
	}
	return (0);
}

char	*ft_initialize(char *buffer)
{
	char		*new;
	ssize_t		i;
	ssize_t		l;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	new = malloc((ft_strlengnl(&buffer[i]) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i++;
	l = 0;
	while (buffer[i + l])
	{
		new[l] = buffer[i + l];
		buffer[l] = buffer[i + l];
		l++;
	}
	new[l] = '\0';
	while (l <= BUFFER_SIZE + 1)
	{
		buffer[l] = '\0';
		l++;
	}
	return (new);
}
