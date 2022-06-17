/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:45:25 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/17 01:50:31 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_player_orientation(t_param *world, char tag)
{
	if (tag == 'N')
		world->orient = 90;
	else if (tag == 'S')
		world->orient = 270;
	else if (tag == 'E')
		world->orient = 0;
	else if (tag == 'W')
		world->orient = 180;
	world->px_x_pos = world->map_x_pos + 0.5;
	world->px_y_pos = world->map_y_pos + 0.5;
}

void	get_player_position(t_param *world)
{
	size_t	x;
	size_t	y;
	int		found_pos;

	y = 0;
	found_pos = 0;
	while (world->map[y])
	{
		x = 0;
		while (world->map[y][x])
		{
			if (ft_char_in_str(world->map[y][x], "NSWE"))
			{
				found_pos++;
				world->map_x_pos = x;
				world->map_y_pos = y;
				get_player_orientation(world, world->map[y][x]);
			}
			x++;
		}
		y++;
	}
	if (found_pos != 1)
		error_exit("Corrupted .cub file", world, NULL, -1);
}
