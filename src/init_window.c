/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:13:03 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/17 18:26:25 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//orientation de 0 a 90 haut gauche de 0  a pi / 2 radian
//orientation de 90 a 180 haut droite de pi/2 a pi radian 
//orientation de 180 a 270 bas droite de pi a 1.5 pi radian
//orientation de 270 a 360 bas gauche de 1.5 pi radian a  2 pi radian








void	init_window(t_param *world)
{
	// int	x;
	// int	y;
	/*	Initialize a window and sets the hooks	*/

// printf("parsing done \n");
	world->img = malloc(sizeof(t_data));
	world->calque = malloc(sizeof(t_data));
	// world->key = malloc(sizeof(t_data));
	world->texture = malloc(sizeof(t_data) * 6);
	if (!world->img || !world->texture || !world->calque)
		error_exit("malloc error", world);
	if (world->img)
	{
		world->video = mlx_init();
		world->texture[NO].img = mlx_xpm_file_to_image(world->video, world->no, &(world->texture[NO].x_size), &(world->texture[NO].y_size));
		world->texture[SO].img = mlx_xpm_file_to_image(world->video, world->so, &(world->texture[SO].x_size), &(world->texture[SO].y_size));
		world->texture[WE].img = mlx_xpm_file_to_image(world->video, world->we, &(world->texture[WE].x_size), &(world->texture[WE].y_size));
		world->texture[EA].img = mlx_xpm_file_to_image(world->video, world->ea, &(world->texture[EA].x_size), &(world->texture[EA].y_size));
		world->texture[DO].img = mlx_xpm_file_to_image(world->video, world->door, &(world->texture[DO].x_size), &(world->texture[DO].y_size));
		world->texture[KE].img = mlx_xpm_file_to_image(world->video, "./texture/keyblade.xpm", &(world->texture[KE].x_size), &(world->texture[KE].y_size));
		//world->texture[EN].img = mlx_xpm_file_to_image(world->video, "./texture/victory.xpm", &(world->texture[EN].x_size), &(world->texture[EN].y_size));
		if (!world->texture[NO].img || !world->texture[SO].img || !world->texture[WE].img || !world->texture[EA].img || !world->texture[DO].img || ! world->texture[KE].img)
			error_exit("Img doesn't exists", world);
		world->window = mlx_new_window(world->video, world->nbray, SCREEN_HEIGHT, "test");
		world->img->img = mlx_new_image(world->video, world->nbray, SCREEN_HEIGHT);
		world->calque->img = mlx_new_image(world->video, world->nbray, SCREEN_HEIGHT);
		world->calque->x_size = world->nbray;
		world->calque->y_size = SCREEN_HEIGHT;
// printf("image inititalised\n");
		world->img->bits_per_pixel = 0;
		world->img->line_length = 0;
		world->img->endian = 0;
		world->img->addr = mlx_get_data_addr(world->img->img, &world->img->bits_per_pixel, &world->img->line_length, &world->img->endian);
		world->calque->addr = mlx_get_data_addr(world->calque->img, &world->calque->bits_per_pixel, &world->calque->line_length, &world->calque->endian);
		// colorise(world->key, world->nbray, SCREEN_HEIGHT);
		world->texture[NO].addr = mlx_get_data_addr(world->texture[NO].img, &world->texture[NO].bits_per_pixel, &world->texture[NO].line_length, &world->texture[NO].endian);
		world->texture[SO].addr = mlx_get_data_addr(world->texture[SO].img, &world->texture[SO].bits_per_pixel, &world->texture[SO].line_length, &world->texture[SO].endian);
		world->texture[WE].addr = mlx_get_data_addr(world->texture[WE].img, &world->texture[WE].bits_per_pixel, &world->texture[WE].line_length, &world->texture[WE].endian);
		world->texture[EA].addr = mlx_get_data_addr(world->texture[EA].img, &world->texture[EA].bits_per_pixel, &world->texture[EA].line_length, &world->texture[EA].endian);
		world->texture[DO].addr = mlx_get_data_addr(world->texture[DO].img, &world->texture[DO].bits_per_pixel, &world->texture[DO].line_length, &world->texture[DO].endian);
		world->texture[KE].addr = mlx_get_data_addr(world->texture[KE].img, &world->texture[KE].bits_per_pixel, &world->texture[KE].line_length, &world->texture[KE].endian);
		//world->texture[EN].addr = mlx_get_data_addr(world->texture[EN].img, &world->texture[EN].bits_per_pixel, &world->texture[EN].line_length, &world->texture[EN].endian);
		// draw_view(world);
// printf("launched mlx\n");
		mlx_hook(world->window, 2, 1L << 0, keyboard_press, world);
		mlx_hook(world->window, 3, 1L << 1, keyboard_release, world);
		mlx_hook(world->window, 17, 1L << 5, exit_cub3d, world);
		// mlx_mouse_move(world->video, 0, 0);
		// mlx_mouse_get_pos(world->video, &x, &y);
		// mlx_do_key_autorepeaton(world->video);
		// mlx_mouse_hook(world->video, &mouse_gest, world);
		// printf(" x=  y = \n");
		mlx_loop_hook(world->video, draw_view, world);
		mlx_loop(world->video);
	}
	free (world->img);
}

// int	draw_view(t_param *world)
// {
// 	/*	Function that will output the visuals	*/

// 	double	offset;
// 	double	dist;
// 	double	x_wall;

// 	offset = ANGLEVISION;
// 	keyboard(world);
// 	x_wall = 0;
// 	if (world->flag_anim == FALSE)
// 	{
// 		if (world->offset_anim > 30 / world->player_front)
// 			world->flag_anim = TRUE;
// 		world->offset_anim++;
// 	}
// 	else if (world->flag_anim == TRUE)
// 	{
// 		if (world->offset_anim < -30 / world->player_front)
// 			world->flag_anim = FALSE;
// 		world->offset_anim--;
// 	}
// 	colorise(world->calque, world->calque->x_size, world->calque->y_size);
// 	while (offset >= 0)
// 	{
// 		dist = calcul_dist_till_wall(world, world->orient - offset + world->mid, &x_wall);
// 		if ((int)offset == world->mid)
// 		{
// 			world->flag_frontdoor = (char)world->flag_wall;
// 			world->player_front = dist;
// 		}
// 		draw_col(world, dist, offset, x_wall);
// 		if (world->keyfound == TRUE)
// 			draw_key(world, offset, dist);
// 		offset -= ECAR;
// 		// world->keyfound = FALSE;
// 	}
// 	// printf("player left = %f", world->player_left);
// 	world->player_left = calcul_dist_till_wall(world, world->orient + 90, &x_wall);
// 	world->player_right = calcul_dist_till_wall(world, world->orient - 90, &x_wall);
// 	world->player_back = calcul_dist_till_wall(world, world->orient - 180, &x_wall);
// 	draw_minimap(world);
// 	// mlx_put_image_to_window(world->video, world->window, world->clean, 0, 0);
// 	mlx_put_image_to_window(world->video, world->window, world->img->img, 0, 0);
// 	mlx_put_image_to_window(world->video, world->window, world->calque->img, 0, 0);
// 	world->keyfound = FALSE;
// 	world->dist_key = -1;
// 	return (0);
// }

// void	draw_key(t_param *world, double offset, double dist)
// {
// 	int	x;
// 	int	y;
// 	int	key_size;
// 	int	mid;
// 	double	x_texture;
// 	double	y_texture;
// 	unsigned int 	color;
// 	// t_bool	found;

// 	if (world->dist_key < 0.1 || world->x_wallkey < 0)
// 	{
// 		// world->keyfound = FALSE;
// 		return ;
// 	}
// 	// found = FALSE;
// 	// printf("dist key = %f\n", world->dist_key);
// 	x = ((double)world->nbray * offset / (double)ANGLEVISION);
// 	key_size = SCREEN_HEIGHT * 0.5 / world->dist_key;
// 	mid = world->half_screen + (world->offset_anim);
// 	y_texture = 0;
// 	y = 0;
// 	x_texture = world->x_wallkey * world->texture[KE].x_size;
// 	if (x_texture < 0)
// 		world->keyfound = FALSE;
// 	if (key_size > SCREEN_HEIGHT)
// 		y_texture = ((key_size * 2) - SCREEN_HEIGHT) * (double)(world->texture[world->flag_wall].y_size) / (double)((key_size * 2)) / 2;
// 	while (y <= SCREEN_HEIGHT && x_texture <= world->texture[KE].x_size)
// 	{
// 		if (y > mid - key_size && y < mid + key_size && world->dist_key < dist)
// 		{
// 			// x_texture = world->x_wallkey * world->texture[KE].x_size;
// 			// world->x_wallkey += 1;
// 			// printf("%f\n", world->x_wallkey);
// 			// if (x_texture > world->texture[world->flag_wall].x_size)
// 			// 	printf("x texture = %d et world->texture[world->flag_wall].x_size = %d \n", x_texture, world->texture[world->flag_wall].x_size);
// 			y_texture += (double)(world->texture[KE].y_size) / (double)((key_size * 2));
// 			if (y_texture >= world->texture[KE].y_size)
// 				y_texture = world->texture[KE].y_size - 1;
// 			// color = get_color_from_img(&world->texture[KE], x_texture, y_texture);
// // printf(" x_texture = %f key_size = %d xwall_key = %f\n", x_texture, key_size, world->x_wallkey);
// 			if ((color = get_color_from_img(&world->texture[KE], x_texture, y_texture)) != 0xff000000)
// 			{
// 			pixel_to_image(world->calque, x, y, color);
// 			}
// 			// printf("color = %x\n", color);
// 		}
// 		y++;
// 	}
// 	world->x_wallkey -= (double)0.5 / (double)key_size;
// // printf("xwalkey = %f\n", world->x_wallkey);
// 	// printf("xwalkey = %f\n", world->x_wallkey);
// 	// if (found == FALSE && x_texture > world->texture[KE].x_size / 2)
// 	// {
// 	// 	world->keyfound = FALSE;
// 		// world->dist_key = -1;
// 	// }
// }

