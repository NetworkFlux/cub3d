/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:03:54 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/14 15:31:28 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	paint_square_map(unsigned int x, unsigned int y, unsigned int square_length, t_param *world)
{
	/*	Draw a single square of the minimap	*/

	unsigned int i;
	unsigned int j;

	i = 0;	// offset pour afficher une fausse grille
	while (i < square_length)
	{
		j = 0;
		while (j < square_length)
		{
			if (world->map[x][y] == '1')
				pixel_to_image(world->img, y * square_length + i, x * square_length + j, 0x00ffffff);	// couleur des cases mur
			else if (world->map[x][y] == ' ' || !world->map[x][y])
			{
				j++;
				continue;
			}
			else if (world->map[x][y] != 'v')
				pixel_to_image(world->img, y * square_length + i, x * square_length + j, 0x00808080);	// couleur des cases terrain
			j++;
		}
		i++;
	}
}

void	draw_player_nose(t_param *world, unsigned int square_length)
{
	// end point = x = r cosθ and y = r sinθ
	unsigned int	new_x;
	unsigned int	new_y;

	new_x = world->map_x_pos + (world->player_front * square_length / (SIZE) * cos(degre_to_radiant(world->orient)));
	new_y = world->map_y_pos - (world->player_front * square_length / (SIZE) * sin(degre_to_radiant(world->orient)));
	if (new_x < (unsigned int)world->map_x_pos)
		new_x++;
	if (new_y < (unsigned int)world->map_y_pos)
		new_y++;
	bresenham(world->map_x_pos, world->map_y_pos, new_x, new_y, world);
}

void	draw_player(t_param *world, unsigned int square_length)
{
	/*	Draws the player on the minimap	*/

	int	i;
	int	j;

	world->player_size = square_length / 2;
	world->map_x_pos = ((((world->px_x_pos / SIZE) * square_length) + ((world->px_x_pos % SIZE) * square_length / SIZE)));
	world->map_y_pos = ((((world->px_y_pos / SIZE) * square_length) + ((world->px_y_pos % SIZE) * square_length / SIZE)));
	//printf("p_map_x = ");
	i = 0;
	while (i < world->player_size)
	{
		j = 0;
		while (j < world->player_size)
			pixel_to_image(world->img, world->map_x_pos - (world->player_size / 3) + i, world->map_y_pos - (world->player_size / 3) + j++, 0x00000000);
		i++;
	}
	//world->p_x_mid = world->p_map_x + world->p_size;
	draw_player_nose(world, square_length);
}

void	draw_minimap(t_param *world)
{
	/*	Draeing of the minimap	*/

	unsigned int	square_length; // longueur des cotes des carres de la minimap
	unsigned int	i;
	unsigned int	j;

	if (world->map_width > world->map_height)
		square_length = (world->nbray / 3) / world->map_width;
	else
		square_length = (world->nbray / 3) / world->map_height ;
	i = 0;
	while (i < world->map_height)
	{
		j = 0;
		while (j < world->map_width)
			paint_square_map(i, j++, square_length, world);
		i++;
	}
	draw_player(world, square_length);
}