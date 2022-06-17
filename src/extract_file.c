/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:24:13 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/17 01:46:51 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_map_start(t_param *world, const char *holder)
{
	static int	start_counting;
	static int	i;

	if (counter_check(world->counter) == 2)
		error_exit("Corrupted .cub file", world, NULL, -1);
	if (counter_check(world->counter) == 0 && start_counting <= 1)
	{
		world->map_start = i;
		if (ft_strlen(holder) > 1)
			start_counting++;
	}
	i++;
}

void	extract_f_c(t_param *world, char **split)
{
	if (len_array_2d(split) == 2)
	{
		if (ft_strsame(split[0], "F"))
		{
			world->floor_color = to_hex_int(split[1], world);
			world->counter[4] += 1;
		}
		else if (ft_strsame(split[0], "C"))
		{
			world->ceiling_color = to_hex_int(split[1], world);
			world->counter[5] += 1;
		}
	}
}

void	extract_sand_rose(t_param *world, char **split)
{
	if (len_array_2d(split) == 2)
	{
		if (ft_strsame(split[0], "NO"))
		{
			world->no = ft_strdup(split[1]);
			world->counter[0] += 1;
		}
		else if (ft_strsame(split[0], "SO"))
		{
			world->so = ft_strdup(split[1]);
			world->counter[1] += 1;
		}
		else if (ft_strsame(split[0], "WE"))
		{
			world->we = ft_strdup(split[1]);
			world->counter[2] += 1;
		}
		else if (ft_strsame(split[0], "EA"))
		{
			world->ea = ft_strdup(split[1]);
			world->counter[3] += 1;
		}
	}
}

void	loop_in_file(t_param *world, int fd)
{
	char	*holder;
	char	**split;

	(void)world;
	holder = NULL;
	split = NULL;
	while (get_next_line(fd, &holder))
	{
		map_data_check(world, holder);
		split = ft_split(holder, ' ');
		extract_sand_rose(world, split);
		extract_f_c(world, split);
		find_map_start(world, holder);
		free_split(split);
		free(holder);
	}
	free(holder);
	extract_map(world);
}

void	extract_file( t_param *world, int fd)
{
	int	i;

	world->counter = malloc(sizeof(int) * 6);
	if (!world->counter)
		error_exit("Malloc error", world, NULL, -1);
	i = 0;
	while (i < 6)
		world->counter[i++] = 0;
	loop_in_file(world, fd);
}
