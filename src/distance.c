/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:54:13 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/14 21:27:58 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	calcul_dist_till_wall(t_param *world, double orientation, double *x_wall)
{
	double	vert;
	double	hor;
	double	dest;
	double	hor_x_wall;
	double	vert_x_wall;

	hor_x_wall = 0;
	vert_x_wall = 0;
	while (orientation < 0)
		orientation += 360;
	if (orientation >= 360)
		orientation = fmod(orientation, 360);
	vert = next_vert_wall(world, orientation, &vert_x_wall);
	hor = next_hor_wall(world, orientation, &hor_x_wall);
	if (vert < hor)
	{
		*x_wall = vert_x_wall;
		dest = vert;
		if (orientation < 90 || orientation > 270)
			world->flag_wall = EA;
		else
			world->flag_wall = WE;
	}
	else
	{
		*x_wall = hor_x_wall;
		dest = hor;
		if (orientation > 0 && orientation < 180)
			world->flag_wall = NO;
		else
			world->flag_wall = SO;
	}
	if (world->orient - orientation != 90 && world->orient - orientation != 270 && world->orient - orientation != -90 && world->orient - orientation != -270)
		dest = dest * cos(degre_to_radiant(world->orient - orientation));
	if (dest < 0)
		dest = dest * (-1);
	return (dest);
}

double	next_vert_wall(t_param *world, double orientation, double *vert_x_wall)
{
	double	decal;
	int		next_vert;
	double	tan_orientation;

	next_vert = 0;
	decal = 0;
	tan_orientation = tan(degre_to_radiant(orientation));
	if (orientation < 90 || orientation > 270)
	{
		next_vert = SIZE - (world->px_x_pos % SIZE);
		decal = (-1 * next_vert * tan_orientation);
		while (check_right_wall(next_vert + world->px_x_pos, decal + world->px_y_pos, world) == FALSE)
		{
			next_vert += SIZE;
			decal = (-1 * next_vert * tan_orientation);
		}
	}
	else if (orientation > 90 && orientation < 270)
	{
		next_vert = (world->px_x_pos % SIZE) * (-1);
		decal = (-1 * next_vert * tan_orientation);
		while (check_left_wall(next_vert + world->px_x_pos, decal + world->px_y_pos, world)== FALSE)
		{
			next_vert -= SIZE;
			decal = (-1 * next_vert * tan_orientation);
		}
	}
	*vert_x_wall = fmod((decal + world->px_y_pos), 64);
	if (orientation == 270 || orientation == 90)
		return (DBL_MAX);
	else
		return (sqrt(pow(next_vert, 2) + pow(decal, 2)));
}

double	next_hor_wall(t_param *world, double orientation, double *hor_x_wall)
{
	double	decal;
	int		next_hor;
	double	cotan_orientation;

	next_hor = 0;
	decal = 0;
	cotan_orientation = (1 / tan(degre_to_radiant(orientation)));
	if (orientation > 0 && orientation < 180)
	{
		next_hor = (world->px_y_pos % SIZE) * (-1);
		decal = -1 * (next_hor * cotan_orientation);
		while (check_up_wall(next_hor + world->px_y_pos, decal + world->px_x_pos, world) == FALSE)
		{
			next_hor -= SIZE;
			decal = -1 * (next_hor * cotan_orientation);
		}
	}
	else if (orientation > 180)
	{
		next_hor =  SIZE - (world->px_y_pos % SIZE);
		decal = -1 * (next_hor * cotan_orientation);
		while (check_down_wall(next_hor + world->px_y_pos, decal + world->px_x_pos, world)== FALSE)
		{
			next_hor += SIZE;
			decal = -1 * (next_hor * cotan_orientation);
		}
	}
	*hor_x_wall = fmod((decal + world->px_x_pos), 64);
	if (orientation == 0 || orientation == 180)
		return (DBL_MAX);
	else
		return (sqrt(pow(next_hor, 2) + pow(decal, 2)));
}
