/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extractor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:55:03 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/08 16:25:07 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	valid_map_line(const char *holder)
{
	/*	Finds out if the map line is valid	*/

	char	*base;
	size_t	i;

	base = " 01NSEW";
	i = 0;
	while (holder[i])
	{
		if (!ft_char_in_str(holder[i], base))
			return (0);
		i++;
	}
	return (1);
}

void	map_data_check(t_param *world, const char *holder)
{
	/*	Verify if every "map" line is valid and gets the amounts of lines and columns	*/
	if (valid_map_line(holder) && ft_strlen(holder) > 1)
	{
		world->map_height++;
		if (ft_strlen(holder) > world->map_width)
			world->map_width = ft_strlen(holder); // il manque une ligne si le fichier ne se termine pas par une ligne vide
	}
}

void	get_player_position(t_param *world)
{
	/*	Gets the player position in the map	*/

	size_t	x;
	size_t	y;

	x = 0;
	while (world->map[x])
	{
		y = 0;
		while (world->map[x][y])
		{
			if (ft_char_in_str(world->map[x][y], "NSEW"))
			{
				world->map_x_pos = y;
				world->map_y_pos = x;
				if (world->map[x][y] == 'N')
					world->orient = 90;
				else if (world->map[x][y] == 'S')
					world->orient = 270;
				else if (world->map[x][y] == 'E')
					world->orient = 0;
				else if (world->map[x][y] == 'W')
					world->orient = 180;
			}
			y++;
		}
		x++;
	}
}

void	fill_spaces(t_param * world)
{
	/*	Replaces all the spaces in the map by walls	*/

	size_t	i;
	size_t	j;

	i = 0;
	while (i < world->map_height)
	{
		j = 0;
		while (j < world->map_width)
		{
			if (world->map[i][j] == ' ')
				world->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

void	last_map_check(t_param *world)
{
	size_t	i;

	i = 0;
	while (i < world->map_height)
	{
		if (world->map[i][0] != '1' || world->map[i][world->map_width - 1] != '1')
			error_exit("Corrupted .cub file ", world);
		i++;
	}
	i = 0;
	while (i < world->map_width)
	{
		if (world->map[0][i] != '1' || world->map[world->map_height - 1][i] != '1')
			error_exit("Corrupted .cub file ", world);
		i++;
	}
}

void	extract_map(t_param *world)
{

	/*	Extract the entire map datas	*/

	int		fd;
	char	*holder;
	size_t	i;

	holder = NULL;
	i = 0;
	world->map = malloc(sizeof(char *) * world->map_height + 1);
	if (!world->map)
		error_exit("Malloc error ", world);
	fd = open(world->path, O_RDONLY);
	if (!fd)
		error_exit("Failed to open the .cub file ", world);
	while (get_next_line(fd, &holder))
	{
		if (valid_map_line(holder) && ft_strlen(holder) > 1)
			world->map[i++] = ft_strjoin(holder, space_string(world->map_width - ft_strlen(holder), world));
	}
	world->map[i] = NULL;
	fill_spaces(world);
	last_map_check(world);
	get_player_position(world);
}
