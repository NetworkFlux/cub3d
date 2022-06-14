/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extractor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:55:03 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/14 17:50:07 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	int		found;

	x = 0;
	found = 0;
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
				found++;
			}
			y++;
		}
		x++;
	}
	if (world->orient == 1000 || found > 1)
		error_exit("Corrupted .cub file ", world);
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
void	check_map_end(t_param *world, size_t i)
{
	int	diff;
	int	j;

	diff = 0;
	if (i < world->map_height - 1)
	{
		if (ft_strlen(world->map[i]) != ft_strlen(world->map[i + 1]))
			diff = ft_strlen(world->map[i]) - ft_strlen(world->map[i + 1]);
		printf("line %zu : %zu, line %zu :%zu, Diff : %d\n",i, ft_strlen(world->map[i]), i + 1, ft_strlen(world->map[i + 1]), diff);
		// if (world->map[i][ft_strlen(world->map[i]) - 1] != '1' && world->map[i][ft_strlen(world->map[i]) - 1] != 'v')
		// 	error_exit("Corrupted .cub file", world);
		// j = 0;
		// while (j < diff - 1)
		// {
		// 	if (world->map[i][ft_strlen(world->map[i + 1]) + j] != '1')
		// 		error_exit("Corrupted .cub file", world);
		// 	j++;
		// }
		j = 0;
		while (j > diff + 1)
		{
			if (world->map[i + 1][ft_strlen(world->map[i]) - 1 ] != '1')
			{
				if (world->map[i + 1][ft_strlen(world->map[i]) + j + 1] != '1')
					error_exit("Corrupted .cub file", world);
			}
			j--;
		}
	}
}

void	last_map_check(t_param *world)
{
	size_t	i;

	i = 0;
	while (world->map[i])
	{
		if (world->map[i][0] != '1' && world->map[i][0] != 'v')
			error_exit("Corrupted .cub file ", world);
		check_map_end(world, i);
		i++;
	}
	// i = 0;
	// while (i < world->map_width)
	// {
	// 	if ((world->map[0][i] != 'v' && world->map[0][i] != '1') || (world->map[world->map_height - 1][i] != '1' && world->map[world->map_height - 1][i] != 'v'))
	// 		error_exit("Corrupted .cub file ", world);
	// 	i++;
	// }
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
	//printf("world map start : %d\n", world->map_start);
	while (i < world->map_start - 1)
	{
		get_next_line(fd, &holder);
		i++;
	}
	i = 0;
	//printf("map width : %d\n", world->map_width);
	while (get_next_line(fd, &holder))
	{
		if (valid_map_line(holder) && ft_strlen(holder) > 1)
			world->map[i++] = ft_substr(holder, 0, ft_strlen(holder));
		else if (!valid_map_line(holder))
			error_exit("Corrupted .cub file ", world);
	}
	world->map[i] = NULL;
	i = 0;
	while (world->map[i])
		printf("%s\n", world->map[i++]);
	fill_spaces(world);
	printf("\n\n\n");
	i = 0;
	while (world->map[i])
		printf("%s\n", world->map[i++]);
	last_map_check(world);
	get_player_position(world);
}
