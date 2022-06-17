/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 23:54:31 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/17 01:46:42 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*space_string(size_t len, t_param *world)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		error_exit("Malloc error ", world, NULL, -1);
	while (i < len)
		res[i++] = 'v';
	res[i] = '\0';
	return (res);
}
