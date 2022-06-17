/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:19:15 by swautele          #+#    #+#             */
/*   Updated: 2022/06/17 19:01:43 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	keyboard(t_param *world)
{
	if (world->flag_rotateleft == TRUE)
		world->orient = (world->orient + ROTATE) % 360;
	if (world->flag_rotateright == TRUE)
	{
		world->orient = world->orient - ROTATE;
		if (world->orient < 0)
			world->orient += 360;
	}
	if (world->flag_front == TRUE)
		move_forward(world);
	if (world->flag_left == TRUE)
		move_left(world);
	if (world->flag_right == TRUE)
		move_right(world);
	if (world->flag_back == TRUE)
		move_back(world);
	return (0);
}

int	keyboard_press(int keycode, t_param *world)
{
	if (keycode == 14)
		open_door(world);
	if (keycode == 123)
		world->flag_rotateleft = TRUE;
	if (keycode == 124)
		world->flag_rotateright = TRUE;
	if (keycode == 13)
		world->flag_front = TRUE;
	if (keycode == 53)
		exit_cub3d(world);
	if (keycode == 0)
		world->flag_left = TRUE;
	if (keycode == 2)
		world->flag_right = TRUE;
	if (keycode == 1)
		world->flag_back = TRUE;
	return (0);
}

int	keyboard_release(int keycode, t_param *world)
{
	if (keycode == 123)
		world->flag_rotateleft = FALSE;
	if (keycode == 124)
		world->flag_rotateright = FALSE;
	if (keycode == 13)
		world->flag_front = FALSE;
	if (keycode == 0)
		world->flag_left = FALSE;
	if (keycode == 2)
		world->flag_right = FALSE;
	if (keycode == 1)
		world->flag_back = FALSE;
	return (0);
}
