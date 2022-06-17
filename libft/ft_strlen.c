/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:12:50 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/17 15:25:09 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	This function returns the total length of
	the const char *s input.	*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	// Basic protection
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
