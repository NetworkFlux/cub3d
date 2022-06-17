/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:21:25 by swautele          #+#    #+#             */
/*   Updated: 2022/06/17 18:25:26 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

void	colorise(t_data *img, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			pixel_to_image(img, i, j, 0xff000000);
			j++;
		}
		i++;
	}
}

void	open_door(t_param *world)
{
	int	x;
	int	y;

	x = (int)world->px_x_pos;
	y = (int)world->px_y_pos;
	if (world->player_front < 2 && world->flag_frontdoor && world->key_picked)
	{
		if (world->orient >= 45 && world->orient < 135
			&& world->map[y - 1][x] == 'D')
			world->map[y - 1][x] = '0';
		else if (world->orient >= 135 && world->orient < 225
			&& world->map[y][x - 1] == 'D')
			world->map[y][x - 1] = '0';
		else if (world->orient >= 225 && world->orient < 315
			&& world->map[y + 1][x] == 'D')
			world->map[y + 1][x] = '0';
		else if ((world->orient >= 315 || world->orient < 45)
			&& world->map[y][x + 1] == 'D')
			world->map[y][x + 1] = '0';
	}
	if (world->map[y][x] == 'K')
	{
		world->map[y][x] = '0';
		world->key_picked = TRUE;
	}
}
