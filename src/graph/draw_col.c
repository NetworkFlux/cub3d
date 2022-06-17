/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:26:09 by swautele          #+#    #+#             */
/*   Updated: 2022/06/17 18:32:59 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

typedef struct s_col{
	int		x;
	int		y;
	int		offset_wall;
	int		mid;
	int		x_texture;
	double	y_texture;
}t_col;

void	col_loop(t_param *world, t_col *f)
{
	if (f->y < f->mid - f->offset_wall)
	{
		pixel_to_image(world->img, f->x, f->y, world->ceiling_color);
	}
	else if (f->y >= f->mid + f->offset_wall)
	{
		pixel_to_image(world->img, f->x, f->y, world->floor_color);
	}
	else
	{
		f->y_texture += (double)(world->texture[world->flag_wall].y_size)
			/ (double)((f->offset_wall * 2));
		if (f->y_texture >= world->texture[world->flag_wall].y_size)
			f->y_texture = world->texture[world->flag_wall].y_size - 1;
		pixel_to_image(world->img, f->x, f->y,
			get_color_from_img(&world->texture[world->flag_wall],
				f->x_texture, f->y_texture));
	}
	f->y++;
}

void	draw_col(t_param *world, double dist, double offset, double x_wall)
{
	t_col	f;

	f.x = world->nbray * offset / ANGLEVISION;
	f.y = 0;
	f.offset_wall = SCREEN_HEIGHT * 0.5 / dist;
	f.mid = world->half_screen;
	f.y_texture = 0;
	f.x_texture = x_wall * (double)world->texture[world->flag_wall].x_size;
	if (f.offset_wall * 2 > SCREEN_HEIGHT)
		f.y_texture = ((f.offset_wall * 2) - SCREEN_HEIGHT)
			* (double)(world->texture[world->flag_wall].y_size)
			/ (double)((f.offset_wall * 2)) / 2;
	while (f.y <= SCREEN_HEIGHT)
	{
		col_loop(world, &f);
	}
}
