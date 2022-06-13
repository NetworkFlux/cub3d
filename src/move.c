/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:13:27 by swautele          #+#    #+#             */
/*   Updated: 2022/06/10 14:15:39 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_param *world)
{
	/*	Makes the player move foreward	*/

	// printf("i try to move p_front = %f\n", world->p_front);
	//printf("i moved to %d %d and p_orient = %d p_front = %f\n", world->p_y_pos, world->p_x_pos, world->p_orient,  world->p_front);
	if (world->player_front > LIMIT)
	{
		if (world->orient == 0)
			world->px_x_pos += MOVE;
		else if (world->orient == 90)
			world->px_y_pos -= MOVE;
		else if (world->orient == 180)
			world->px_x_pos -= MOVE;
		else if (world->orient == 270)
			world->px_y_pos += MOVE;
		else
		{
			world->px_x_pos += cos(degre_to_radiant(world->orient)) * 8;
			world->px_y_pos -= sin(degre_to_radiant(world->orient)) * 8;
		}
		// draw_view(world);
	}
}

void	move_left(t_param *world)
{
	int	dir;

	dir = world->orient + 90;
	// printf("%d et %f\n", dir, world->player_left);
	if (world->player_left > LIMIT)
	{
		if (dir == 0)
			world->px_x_pos += MOVE;
		else if (dir == 90)
			world->px_y_pos -= MOVE;
		else if (dir == 180)
			world->px_x_pos -= MOVE;
		else if (dir == 270)
			world->px_y_pos += MOVE;
		else
		{
			world->px_x_pos += cos(degre_to_radiant(dir)) * 8;
			world->px_y_pos -= sin(degre_to_radiant(dir)) * 8;
		}
	}
}

void	move_right(t_param *world)
{
	int	dir;

	dir = world->orient - 90;
	if (world->player_right > LIMIT)
	{
		if (dir == 0)
			world->px_x_pos += MOVE;
		else if (dir == 90)
			world->px_y_pos -= MOVE;
		else if (dir == 180)
			world->px_x_pos -= MOVE;
		else if (dir == 270)
			world->px_y_pos += MOVE;
		else
		{
			world->px_x_pos += cos(degre_to_radiant(dir)) * 8;
			world->px_y_pos -= sin(degre_to_radiant(dir)) * 8;
		}
	}
}

void	move_back(t_param *world)
{
	int	dir;

	dir = world->orient + 180;
	if (world->player_back > LIMIT)
	{
		if (dir == 0)
			world->px_x_pos += MOVE;
		else if (dir == 90)
			world->px_y_pos -= MOVE;
		else if (dir == 180)
			world->px_x_pos -= MOVE;
		else if (dir == 270)
			world->px_y_pos += MOVE;
		else
		{
			world->px_x_pos += cos(degre_to_radiant(dir)) * 8;
			world->px_y_pos -= sin(degre_to_radiant(dir)) * 8;
		}
	}
}
