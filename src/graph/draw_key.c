/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:19:38 by swautele          #+#    #+#             */
/*   Updated: 2022/06/17 18:12:20 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

typedef struct s_key{
	int				x;
	int				y;
	int				key_size;
	int				mid;
	double			x_texture;
	double			y_texture;
	unsigned int	color;
}	t_key;

static void	key_loop(t_param *world, t_key *f, double dist)
{
	if (f->y > f->mid - f->key_size && f->y < f->mid
		+ f->key_size && world->dist_key < dist)
	{
		f->y_texture += (double)(world->texture[KE].y_size)
			/ (double)((f->key_size * 2));
		if (f->y_texture >= world->texture[KE].y_size)
			f->y_texture = world->texture[KE].y_size - 1;
		f->color = get_color_from_img(&world->texture[KE],
				f->x_texture, f->y_texture);
		if (f->color != 0xff000000)
			pixel_to_image(world->calque, f->x, f->y, f->color);
	}
	f->y++;
}

void	draw_key(t_param *world, double offset, double dist)
{
	t_key	f;

	if (world->dist_key < 0.1 || world->x_wallkey < 0)
		return ;
	f.x = ((double)world->nbray * offset / (double)ANGLEVISION);
	f.key_size = SCREEN_HEIGHT * 0.5 / world->dist_key;
	f.mid = world->half_screen + (world->offset_anim);
	f.y_texture = 0;
	f.y = 0;
	f.x_texture = world->x_wallkey * world->texture[KE].x_size;
	if (f.x_texture < 0)
		world->keyfound = FALSE;
	if (f.key_size > SCREEN_HEIGHT)
		f.y_texture = ((f.key_size * 2) - SCREEN_HEIGHT)
			* (world->texture[world->flag_wall].y_size)
			/ ((f.key_size * 2)) / 2;
	while (f.y <= SCREEN_HEIGHT && f.x_texture <= world->texture[KE].x_size)
		key_loop(world, &f, dist);
	world->x_wallkey -= (double)0.5 / (double)f.key_size;
}
