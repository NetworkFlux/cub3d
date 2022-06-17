/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:11:25 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/17 13:20:00 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	keyboard_press(int keycode, t_param *world)
{
	if (keycode == 53)
		succes_exit(world, NULL, -1);
	return (0);
}

void	lets_cub(t_param *world)
{
	init_mlx(world);
	mlx_hook(world->window, 2, 1L << 0, keyboard_press, world);
	mlx_loop(world->instance);
}
