/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:54:13 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/17 18:43:34 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

typedef struct s_dist
{
	double	vert;
	double	hor;
	double	dest;
	double	hor_x_wall;
	double	vert_x_wall;
	int		sub_door_vert;
	int		sub_door_hor;
}			t_dist;

static	void	dist_till_wall(t_param *world, t_dist *f, double orientation,
		double *x_wall)
{
	if (f->vert < f->hor)
	{
		*x_wall = f->vert_x_wall;
		f->dest = f->vert;
		if (f->sub_door_vert == 3)
			world->flag_wall = DO;
		else if (orientation < 90 || orientation > 270)
			world->flag_wall = EA;
		else
			world->flag_wall = WE;
	}
	else
	{
		*x_wall = f->hor_x_wall;
		f->dest = f->hor;
		if (f->sub_door_hor == 3)
			world->flag_wall = DO;
		else if (orientation > 0 && orientation < 180)
			world->flag_wall = NO;
		else
			world->flag_wall = SO;
	}
}

double	calcul_dist_till_wall(t_param *world, double orientation,
		double *x_wall)
{
	t_dist	f;

	f.hor_x_wall = 0;
	f.vert_x_wall = 0;
	f.sub_door_hor = 0;
	f.sub_door_vert = 0;
	while (orientation < 0)
		orientation += 360;
	if (orientation >= 360)
		orientation = fmod(orientation, 360);
	f.vert = next_vert_wall(world, orientation, &f.vert_x_wall,
			&f.sub_door_vert);
	f.hor = next_hor_wall(world, orientation, &f.hor_x_wall, &f.sub_door_hor);
	dist_till_wall(world, &f, orientation, x_wall);
	if (world->orient - orientation != 90 && world->orient - orientation != 270
		&& world->orient - orientation != -90 && world->orient - orientation
		!= -270)
		f.dest = f.dest * cos(degre_to_radiant((double)world->orient
					- orientation));
	if (f.dest < 0)
		f.dest = f.dest * (-1);
	return (f.dest);
}
