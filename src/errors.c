/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:55:23 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/17 01:54:00 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clean_close_mlx(t_param *world)
{
	if (world->img)
		mlx_destroy_image(world->instance, world->img->img);
	if (world->clean_img)
		mlx_destroy_image(world->instance, world->clean_img);
	if (world->window)
		mlx_destroy_window(world->instance, world->window);
}

void	succes_exit(t_param *world, char *str_tr_free, int fd_to_close)
{
	clean_close_mlx(world);
	free_world(world);
	free(str_tr_free);
	if (fd_to_close != -1)
		close(fd_to_close);
	system("leaks cub3D");
	exit(EXIT_SUCCESS);
}

void	error_exit(char *message, t_param *world, char *str_tr_free,
	int fd_to_close)
{
	clean_close_mlx(world);
	free_world(world);
	free(str_tr_free);
	if (fd_to_close != -1)
		close(fd_to_close);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	system("leaks cub3D");
	exit(EXIT_FAILURE);
}
