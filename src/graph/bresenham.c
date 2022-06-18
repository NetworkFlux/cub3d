/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:26:34 by swautele          #+#    #+#             */
/*   Updated: 2022/06/17 19:36:48 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

typedef struct s_bres{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}t_bres;

typedef struct s_fuck{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}t_fuck;

static void	bresenham_loop(t_fuck *d, t_param *world, t_bres *f)
{
	while (1)
	{
		pixel_to_image(world->calque, d->x0, y0, 0x00000000);
		if (d->x0 == d->x1 && d->y0 == d->y1)
			break ;
		f->e2 = f->err;
		if (f->e2 > -f->dx)
		{
			f->err -= f->dy;
			d->x0 += f->sx;
		}
		if (f->e2 < f->dy)
		{
			f->err += f->dx;
			d->y0 += f->sy;
		}
	}
}

void	bresenham(t_fuck d, t_param *world)
{
	t_bres	f;

	f.dx = abs(d.x1 - d.x0);
	f.dy = abs(d.y1 - d.y0);
	if (d.x0 < d.x1)
		f.sx = 1;
	else
		f.sx = -1;
	if (y0 < y1)
		f.sy = 1;
	else
		f.sy = -1;
	if (f.dx > f.dy)
		f.err = f.dx / 2;
	else
		f.err = -f.dy / 2;
	bresenham_loop(&d, world, &f);
}