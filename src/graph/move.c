/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:13:27 by swautele          #+#    #+#             */
/*   Updated: 2022/06/17 19:14:40 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_param *world)
{
	if (world->player_front > world->limit)
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
			world->px_x_pos += cos(degre_to_radiant(world->orient)) * MOVE;
			world->px_y_pos -= sin(degre_to_radiant(world->orient)) * MOVE;
		}
	}
}

void	move_left(t_param *world)
{
	int	dir;

	dir = world->orient + 90;
	if (world->player_left > world->limit)
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
			world->px_x_pos += cos(degre_to_radiant(dir)) * MOVE;
			world->px_y_pos -= sin(degre_to_radiant(dir)) * MOVE;
		}
	}
}

void	move_right(t_param *world)
{
	int	dir;

	dir = world->orient - 90;
	if (world->player_right > world->limit)
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
			world->px_x_pos += cos(degre_to_radiant(dir)) * MOVE;
			world->px_y_pos -= sin(degre_to_radiant(dir)) * MOVE;
		}
	}
}

void	move_back(t_param *world)
{
	int	dir;

	dir = world->orient + 180;
	if (world->player_back > world->limit)
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
			world->px_x_pos += cos(degre_to_radiant(dir)) * MOVE;
			world->px_y_pos -= sin(degre_to_radiant(dir)) * MOVE;
		}
	}
}
