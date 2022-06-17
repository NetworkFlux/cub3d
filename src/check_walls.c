/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:17:04 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/17 13:42:17 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_left_wall(double y, double x, t_param *world)
{
	int	new_x;
	int	new_y;

	new_y = y;
	new_x = (x) - 1;
	if (new_y >= (int)world->map_height || new_x >= (int)world->map_width || new_x < 0 || new_y < 0)
		return (TRUE);
	if (world->map[new_y][new_x] == 'K')
	{
		if (world->keyfound == FALSE)
		{
			world->keyfound = TRUE;
			world->dist_key = sqrt(pow((y + 0.5) - world->px_y_pos, 2) + pow((x + 0.5) - world->px_x_pos, 2));
			world->x_wallkey = fmod(y, 1);
			if (world->x_wallkey == 0)
				world->x_wallkey = 1;
		}
		// printf("i foudn q key dist = %f\n", world->dist_key);
		// return (4);
	}
	if (world->map[new_y][new_x] == '1')
	{
		// printf("found left wall on %f %f\n", y, x);
		return (TRUE);
	}
	else if (world->map[new_y][new_x] == 'D')
		return (3);
	else
		return (FALSE);
}

int	check_right_wall(double y, double x, t_param *world)
{
	int	new_x;
	int	new_y;

	new_y = y;
	new_x = x;
	if (new_y >= (int)world->map_height || new_x >= (int)world->map_width || new_x < 0 || new_y < 0)
		return (TRUE);
	if (world->map[new_y][new_x] == 'K')
	{
		if (world->keyfound == FALSE)
		{
			world->keyfound = TRUE;
			world->dist_key = sqrt(pow((y + 0.5) - world->px_y_pos, 2) + pow((x + 0.5) - world->px_x_pos, 2));
			world->x_wallkey = fmod(y, 1);
			if (world->x_wallkey == 0)
				world->x_wallkey = 1;
		}
		// printf("i foudn q key dist = %f\n", world->dist_key);
		// return (4);
	}
	if (world->map[new_y][new_x] == '1')
	{
		// printf("found right wall on %f %f\n", y, x);
		return (TRUE);
	}
	else if (world->map[new_y][new_x] == 'D')
		return (3);
	else
		return (FALSE);
}

int	check_up_wall(double y, double x, t_param *world)
{
	int	new_x;
	int	new_y;

	new_y = (y) - 1;
	new_x = x;
	if (new_y >= (int)world->map_height || new_x >= (int)world->map_width || new_y < 0 || new_x < 0)
		return (TRUE);
	if (world->map[new_y][new_x] == 'K')
	{
		if (world->keyfound == FALSE)
		{
			world->keyfound = TRUE;
			world->dist_key = sqrt(pow((y + 0.5) - world->px_y_pos, 2) + pow((x + 0.5) - world->px_x_pos, 2));
			world->x_wallkey = fmod(x, 1);
			if (world->x_wallkey == 0)
				world->x_wallkey = 1;
		}
		// printf("i foudn q key dist = %f\n", world->dist_key);
		// return (4);
	}
	if (world->map[new_y][new_x] == '1')
	{
		// printf("found up wall on %d %d\n", new_y, new_x);
		return (TRUE);
	}
	else if (world->map[new_y][new_x] == 'D')
		return (3);
	else
		return (FALSE);
}

int	check_down_wall(double y, double x, t_param *world)
{
	int	new_x;
	int	new_y;

	new_y = y;
	new_x = x;
	if (new_y >= (int)world->map_height || new_x >= (int)world->map_width || new_x < 0 || new_y < 0)
		return (TRUE);
	if (world->map[new_y][new_x] == 'K')
	{
		if (world->keyfound == FALSE)
		{
			world->keyfound = TRUE;
			world->dist_key = sqrt(pow((y + 0.5) - world->px_y_pos, 2) + pow((x + 0.5) - world->px_x_pos, 2));
			world->x_wallkey = fmod(x, 1);
			if (world->x_wallkey == 0)
				world->x_wallkey = 1;
		}
		// printf("i foudn q key dist = %f\n", world->dist_key);
		// return (4);
	}
	if (world->map[new_y][new_x] == '1')
	{
		// printf("found down wall on %f %f\n", y, x);
		return (TRUE);
	}
	else if (world->map[new_y][new_x] == 'D')
		return (3);
	else
		return (FALSE);
}
