/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:34:32 by swautele          #+#    #+#             */
/*   Updated: 2022/06/17 19:09:05 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

typedef struct s_vert{
	double	decal;
	double	next_vert;
	double	tan_orientation;
}t_vert;

static void	next_right_wall(t_param *world, t_vert *f, int *sub_door_vert)
{
	f->next_vert = 1 - fmod(world->px_x_pos, 1);
	f->decal = (-1 * f->next_vert * f->tan_orientation);
	*sub_door_vert = check_right_wall(f->decal + world->px_y_pos,
			world->px_x_pos + f->next_vert, world);
	while (*sub_door_vert == FALSE)
	{
		f->next_vert += 1;
		f->decal -= f->tan_orientation;
		*sub_door_vert = check_right_wall(f->decal + world->px_y_pos,
				world->px_x_pos + f->next_vert, world);
	}
}

static void	next_left_wall(t_param *world, t_vert *f, int *sub_door_vert)
{
	f->next_vert = fmod(world->px_x_pos, 1) * (-1);
	f->decal = (-1 * f->next_vert * f->tan_orientation);
	*sub_door_vert = check_left_wall(world->px_y_pos + f->decal,
			world->px_x_pos + f->next_vert, world);
	while (*sub_door_vert == FALSE)
	{
		f->next_vert -= 1;
		f->decal += f->tan_orientation;
		*sub_door_vert = check_left_wall(world->px_y_pos + f->decal,
				world->px_x_pos + f->next_vert, world);
	}
}

double	next_vert_wall(t_param *world, double orientation, double *vert_x_wall,
	int *sub_door_vert)
{
	t_vert	f;

	f.next_vert = 0;
	f.decal = 0;
	f.tan_orientation = tan(degre_to_radiant(orientation));
	if (orientation < 90 || orientation > 270)
	{
		next_right_wall(world, &f, sub_door_vert);
	}
	else if (orientation > 90 && orientation < 270)
	{
		next_left_wall(world, &f, sub_door_vert);
	}
	*vert_x_wall = fmod((f.decal + world->px_y_pos), 1);
	if (orientation == 270 || orientation == 90)
		return (DBL_MAX);
	else
		return (sqrt(pow(f.next_vert, 2) + pow(f.decal, 2)));
}
