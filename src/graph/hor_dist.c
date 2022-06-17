/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hor_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:34:04 by swautele          #+#    #+#             */
/*   Updated: 2022/06/17 19:13:18 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

typedef struct s_hor{
	double	decal;
	double	next_hor;
	double	cotan_orientation;
}t_hor;

static void	next_up_wall(t_param *world, t_hor *f, int *sub_door_hor)
{
	f->next_hor = fmod(world->px_y_pos, 1) * (-1);
	f->decal = f->cotan_orientation * (-f->next_hor);
	*sub_door_hor = check_up_wall(f->next_hor + world->px_y_pos, f->decal
			+ world->px_x_pos, world);
	while (*sub_door_hor == FALSE)
	{
		f->next_hor -= 1;
		f->decal += f->cotan_orientation;
		*sub_door_hor = check_up_wall(f->next_hor + world->px_y_pos, f->decal
				+ world->px_x_pos, world);
	}
}

static void	next_down_wall(t_param *world, t_hor *f, int *sub_door_hor)
{
	f->next_hor = 1 - fmod(world->px_y_pos, 1);
	f->decal = -1 * (f->next_hor * f->cotan_orientation);
	*sub_door_hor = check_down_wall(f->next_hor + world->px_y_pos,
			f->decal + world->px_x_pos, world);
	while (*sub_door_hor == FALSE)
	{
		f->next_hor += 1;
		f->decal -= f->cotan_orientation;
		*sub_door_hor = check_down_wall(f->next_hor + world->px_y_pos,
				f->decal + world->px_x_pos, world);
	}
}

double	next_hor_wall(t_param *world, double orientation, double *hor_x_wall,
	int *sub_door_hor)
{
	t_hor	f;

	f.next_hor = 0;
	f.decal = 0;
	f.cotan_orientation = (1 / tan(degre_to_radiant(orientation)));
	if (orientation > 0 && orientation < 180)
	{
		next_up_wall(world, &f, sub_door_hor);
	}
	else if (orientation > 180)
	{
		next_down_wall(world, &f, sub_door_hor);
	}
	*hor_x_wall = fmod((f.decal + world->px_x_pos), 1);
	if (orientation == 0 || orientation == 180)
		return (DBL_MAX);
	else
		return (sqrt(pow(f.next_hor, 2) + pow(f.decal, 2)));
}
