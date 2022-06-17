/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:17:04 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/17 18:18:01 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

typedef struct s_check{
	int	new_x;
	int	new_y;
}t_check;

int	check_left_wall(double y, double x, t_param *world)
{
	t_check	f;

	f.new_y = y;
	f.new_x = (x) - 1;
	if (f.new_y >= (int)world->map_height || f.new_x >= (int)world->map_width
		|| f.new_x < 0 || f.new_y < 0)
		return (TRUE);
	if (world->map[f.new_y][f.new_x] == 'K')
	{
		if (world->keyfound == FALSE)
		{
			world->keyfound = TRUE;
			world->dist_key = sqrt(pow((y + 0.5) - world->px_y_pos, 2)
					+ pow((x + 0.5) - world->px_x_pos, 2));
			world->x_wallkey = fmod(y, 1);
			if (world->x_wallkey == 0)
				world->x_wallkey = 1;
		}
	}
	if (world->map[f.new_y][f.new_x] == '1')
		return (TRUE);
	else if (world->map[f.new_y][f.new_x] == 'D')
		return (3);
	else
		return (FALSE);
}

int	check_right_wall(double y, double x, t_param *world)
{
	t_check	f;

	f.new_y = y;
	f.new_x = x;
	if (f.new_y >= (int)world->map_height || f.new_x >= (int)world->map_width
		|| f.new_x < 0 || f.new_y < 0)
		return (TRUE);
	if (world->map[f.new_y][f.new_x] == 'K')
	{
		if (world->keyfound == FALSE)
		{
			world->keyfound = TRUE;
			world->dist_key = sqrt(pow((y + 0.5) - world->px_y_pos, 2)
					+ pow((x + 0.5) - world->px_x_pos, 2));
			world->x_wallkey = fmod(y, 1);
			if (world->x_wallkey == 0)
				world->x_wallkey = 1;
		}
	}
	if (world->map[f.new_y][f.new_x] == '1')
		return (TRUE);
	else if (world->map[f.new_y][f.new_x] == 'D')
		return (3);
	else
		return (FALSE);
}

int	check_up_wall(double y, double x, t_param *world)
{
	t_check	f;

	f.new_y = (y) - 1;
	f.new_x = x;
	if (f.new_y >= (int)world->map_height || f.new_x >= (int)world->map_width
		|| f.new_y < 0 || f.new_x < 0)
		return (TRUE);
	if (world->map[f.new_y][f.new_x] == 'K')
	{
		if (world->keyfound == FALSE)
		{
			world->keyfound = TRUE;
			world->dist_key = sqrt(pow((y + 0.5) - world->px_y_pos, 2)
					+ pow((x + 0.5) - world->px_x_pos, 2));
			world->x_wallkey = fmod(x, 1);
			if (world->x_wallkey == 0)
				world->x_wallkey = 1;
		}
	}
	if (world->map[f.new_y][f.new_x] == '1')
		return (TRUE);
	else if (world->map[f.new_y][f.new_x] == 'D')
		return (3);
	else
		return (FALSE);
}

int	check_down_wall(double y, double x, t_param *world)
{
	t_check	f;

	f.new_y = y;
	f.new_x = x;
	if (f.new_y >= (int)world->map_height || f.new_x >= (int)world->map_width
		|| f.new_x < 0 || f.new_y < 0)
		return (TRUE);
	if (world->map[f.new_y][f.new_x] == 'K')
	{
		if (world->keyfound == FALSE)
		{
			world->keyfound = TRUE;
			world->dist_key = sqrt(pow((y + 0.5) - world->px_y_pos, 2)
					+ pow((x + 0.5) - world->px_x_pos, 2));
			world->x_wallkey = fmod(x, 1);
			if (world->x_wallkey == 0)
				world->x_wallkey = 1;
		}
	}
	if (world->map[f.new_y][f.new_x] == '1')
		return (TRUE);
	else if (world->map[f.new_y][f.new_x] == 'D')
		return (3);
	else
		return (FALSE);
}
