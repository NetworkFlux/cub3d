/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:33:12 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/13 12:30:28 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	to_hex_int(const char *str, t_param *world)
{
	char	**split;
	int	r;
	int g;
	int b;

	split = ft_split(str, ',');
	if (!(ft_isstrdigit(split[0]) && ft_isstrdigit(split[1]) && ft_isstrdigit(split[2])))
		error_exit("Corrupted .cub file ", world);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	return (0 << 24 | r << 16 | g << 8 | b);
}

size_t	len_array_2d(char **split)
{
	size_t	res;

	res = 0;
	while (split[res])
		res++;
	return (res);
}

int	exit_cub3d(t_param *world)
{
	mlx_destroy_image(world->video, world->img->img);
	mlx_destroy_image(world->video, world->clean);
	mlx_destroy_image(world->video, world->texture[0].img);
	mlx_destroy_image(world->video, world->texture[1].img);
	mlx_destroy_image(world->video, world->texture[2].img);
	mlx_destroy_image(world->video, world->texture[3].img);
	mlx_destroy_window(world->video, world->window);
	free(world->texture);
	free(world->img);
	free(world);
	exit(0);
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	pixel_to_image(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	degre_to_radiant(double degre)
{
	return (M_PI * degre / 180);
}

/*	Algorithme de Bresenham, celle-ci dessine les lignes entre
	deux points.	*/

void	bresenham(int x0, int y0, int x1, int y1, t_param * world)
{
	int	dx, dy, sx, sy, err, e2;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;
	if (dx > dy)
		err = dx / 2;
	else
		err = -dy / 2;
	while (1)
	{
		pixel_to_image(world->img, x0, y0, 0x00000000);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

char	*space_string(size_t len, t_param * world)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		error_exit("Malloc error ", world);
	while (i < len)
		res[i++] = 'v';
	res[i] = '\0';
	return (res);
}