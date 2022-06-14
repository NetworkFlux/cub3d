/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:13:03 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/14 21:28:03 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//orientation de 0 a 90 haut gauche de 0  a pi / 2 radian
//orientation de 90 a 180 haut droite de pi/2 a pi radian 
//orientation de 180 a 270 bas droite de pi a 1.5 pi radian
//orientation de 270 a 360 bas gauche de 1.5 pi radian a  2 pi radian

int	keyboard(int keycode, t_param *world)
{
	/*	All action that can possibly be made by the player	*/

	if (keycode == 123)
		world->orient = (world->orient + 9) % 360;
	if (keycode == 124)
	{
		world->orient = world->orient - 9;
		if (world->orient < 0)
			world->orient += 360;
	}
	if (keycode == 13 || keycode == 126)
		move_forward(world);
	if (keycode == 53)
		exit_cub3d(world);
	if (keycode == 0)
		move_left(world);
	if (keycode == 2)
		move_right(world);
	if (keycode == 1 || keycode == 125)
		move_back(world);
	return (0);
}

void	init_window(t_param *world)
{
	/*	Initialize a window and sets the hooks	*/

	world->img = malloc(sizeof(t_data));
	world->texture = malloc(sizeof(t_data) * 4);
	if (world->img)
	{
		world->video = mlx_init();
		world->texture[NO].img = mlx_xpm_file_to_image(world->video, world->no, &(world->texture[NO].x_size), &(world->texture[NO].y_size));
		world->texture[SO].img = mlx_xpm_file_to_image(world->video, world->so, &(world->texture[SO].x_size), &(world->texture[SO].y_size));
		world->texture[WE].img = mlx_xpm_file_to_image(world->video, world->we, &(world->texture[WE].x_size), &(world->texture[WE].y_size));
		world->texture[EA].img = mlx_xpm_file_to_image(world->video, world->ea, &(world->texture[EA].x_size), &(world->texture[EA].y_size));
		if (!world->texture[NO].img || !world->texture[SO].img || !world->texture[WE].img || !world->texture[EA].img)
			error_exit("Img doesn't exists", world);
		world->window = mlx_new_window(world->video, world->nbray, SCREEN_HEIGHT, "test");
		world->img->img = mlx_new_image(world->video, world->nbray, SCREEN_HEIGHT);
		world->clean = mlx_new_image(world->video, world->nbray, SCREEN_HEIGHT);
		world->img->bits_per_pixel = 0;
		world->img->line_length = 0;
		world->img->endian = 0;
		world->img->addr = mlx_get_data_addr(world->img->img, &world->img->bits_per_pixel, &world->img->line_length, &world->img->endian);
		world->texture[NO].addr = mlx_get_data_addr(world->texture[NO].img, &world->texture[NO].bits_per_pixel, &world->texture[NO].line_length, &world->texture[NO].endian);
		world->texture[SO].addr = mlx_get_data_addr(world->texture[SO].img, &world->texture[SO].bits_per_pixel, &world->texture[SO].line_length, &world->texture[SO].endian);
		world->texture[WE].addr = mlx_get_data_addr(world->texture[WE].img, &world->texture[WE].bits_per_pixel, &world->texture[WE].line_length, &world->texture[WE].endian);
		world->texture[EA].addr = mlx_get_data_addr(world->texture[EA].img, &world->texture[EA].bits_per_pixel, &world->texture[EA].line_length, &world->texture[EA].endian);
		draw_view(world);
		mlx_hook(world->window, 2, 1L << 0, keyboard, world);
		mlx_hook(world->window, 17, 1L << 5, exit_cub3d, world);
		mlx_loop_hook(world->video, draw_view, world);
		mlx_loop(world->video);
	}
	free (world->img);
}

int	draw_view(t_param *world)
{
	/*	Function that will output the visuals	*/

	double	offset;
	double	dist;
	double	x_wall;

	offset = ANGLEVISION;
	mlx_put_image_to_window(world->video, world->window, world->clean, 0, 0);
	x_wall = 0;
	while (offset >= 0)
	{
		dist = calcul_dist_till_wall(world, world->orient - offset + world->mid, &x_wall);
		if ((int)offset == world->mid)
		{
			world->player_front = dist;
		}
		draw_col(world, dist, offset, x_wall);
		offset -= ECAR;
	}
	world->player_left = calcul_dist_till_wall(world, world->orient + 90, &x_wall);
	world->player_right = calcul_dist_till_wall(world, world->orient - 90, &x_wall);
	world->player_back = calcul_dist_till_wall(world, world->orient - 180, &x_wall);
	draw_minimap(world);
	mlx_put_image_to_window(world->video, world->window, world->img->img, 0, 0);
	return (0);
}

void	draw_col(t_param *world, double dist, double offset, double x_wall)
{
	int	x;
	int	y;
	int	offset_wall;
	int	mid;
	double	x_texture;
	double	y_texture;
	// int	i;
	// int	col_width;

	// col_width = SCREEN_WIDTH / NBRAY;
	x = world->nbray * offset / ANGLEVISION;
	y = 0;
	offset_wall = SCREEN_HEIGHT * 15 / dist;
	mid = world->half_screen;
	y_texture = 0;
	if (offset_wall * 2 > SCREEN_HEIGHT)
		y_texture = ((offset_wall * 2) - SCREEN_HEIGHT) * (double)(world->texture[world->flag_wall].y_size) / (double)((offset_wall * 2)) / 2;
	while (y <= SCREEN_HEIGHT)
	{
		if (y < mid - offset_wall)
		{
			// i = -1;
			// while (++i < col_width)
			pixel_to_image(world->img, x, y, world->ceiling_color);
		}
		else if (y >= mid + offset_wall)
		{
			// i = -1;
			// while (++i < col_width)
			pixel_to_image(world->img, x, y, world->floor_color);
		}
		else
		{
			x_texture = x_wall * world->texture[world->flag_wall].x_size / SIZE;
			y_texture += (double)(world->texture[world->flag_wall].y_size) / (double)((offset_wall * 2));
			if (y_texture >= world->texture[world->flag_wall].y_size)
				y_texture = world->texture[world->flag_wall].y_size - 1;
			// i = -1;
			// while (++i < col_width)
			pixel_to_image(world->img, x, y, get_color_from_img(&world->texture[world->flag_wall], x_texture, y_texture));
		}
		y++;
	}
}
