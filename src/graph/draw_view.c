/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:13:47 by swautele          #+#    #+#             */
/*   Updated: 2022/06/17 17:19:13 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	void	animate(t_param *world)
{
	if (world->flag_anim == FALSE)
	{
		if (world->offset_anim > 30 / world->player_front)
			world->flag_anim = TRUE;
		world->offset_anim++;
	}
	else if (world->flag_anim == TRUE)
	{
		if (world->offset_anim < -30 / world->player_front)
			world->flag_anim = FALSE;
		world->offset_anim--;
	}
}

static void	set_dist(t_param *world, double x_wall)
{
	world->player_left = calcul_dist_till_wall(world,
			world->orient + 90, &x_wall);
	world->player_right = calcul_dist_till_wall(world,
			world->orient - 90, &x_wall);
	world->player_back = calcul_dist_till_wall(world,
			world->orient - 180, &x_wall);
	draw_minimap(world);
	mlx_put_image_to_window(world->video, world->window,
		world->img->img, 0, 0);
	mlx_put_image_to_window(world->video, world->window,
		world->calque->img, 0, 0);
	world->keyfound = FALSE;
	world->dist_key = -1;
}

int	draw_view(t_param *world)
{
	double	offset;
	double	dist;
	double	x_wall;

	offset = ANGLEVISION;
	keyboard(world);
	x_wall = 0;
	animate(world);
	colorise(world->calque, world->calque->x_size, world->calque->y_size);
	while (offset >= 0)
	{
		dist = calcul_dist_till_wall(world, world->orient
				- offset + world->mid, &x_wall);
		if ((int)offset == world->mid)
		{
			world->flag_frontdoor = (char)world->flag_wall;
			world->player_front = dist;
		}
		draw_col(world, dist, offset, x_wall);
		if (world->keyfound == TRUE)
			draw_key(world, offset, dist);
		offset -= ECAR;
	}
	set_dist(world, x_wall);
	return (0);
}
