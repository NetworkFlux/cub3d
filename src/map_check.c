/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:34:40 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/17 01:50:24 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	last_map_check(t_param *world)
{
	size_t	i;

	i = 0;
	while (i < world->map_height)
	{
		if (world->map[i][0] != '1' ||
			(world->map[i][world->map_width - 1] != '1' &&
			world->map[i][world->map_width - 1] != 'v'))
			error_exit("Corrupted .cub file ", world, NULL, -1);
		i++;
	}
	i = 0;
	while (i < world->map_width)
	{
		if ((world->map[0][i] != 'v' && world->map[0][i] != '1') ||
			(world->map[world->map_height - 1][i] != '1' &&
			world->map[world->map_height - 1][i] != 'v'))
			error_exit("Corrupted .cub file ", world, NULL, -1);
		i++;
	}
}

int	valid_map_line(const char *holder)
{
	char	*base;
	size_t	i;

	base = " 01NSEWDK";
	i = 0;
	while (holder[i])
	{
		if (!ft_char_in_str(holder[i++], base))
			return (0);
	}
	return (1);
}

void	map_data_check(t_param *world, const char *holder)
{
	if (valid_map_line(holder) && ft_strlen(holder) > 1)
	{
		world->map_height++;
		if (ft_strlen(holder) > world->map_width)
			world->map_width = ft_strlen(holder); // il manque une ligne si le fichier ne se termine pas par une ligne vide
	}
}
