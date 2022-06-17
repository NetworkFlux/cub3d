/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2022/05/31 16:34:50 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/17 15:30:31 by simonwautel      ###   ########.fr       */
=======
/*   Created: 2022/06/16 19:11:38 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/17 01:48:10 by npinheir         ###   ########.fr       */
>>>>>>> norm_version
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	extention_check(const char *path)
{
	char	*extention;
	size_t	len;

	len = ft_strlen(path);
	if (len <= 3)
		return (1);
	extention = ft_substr(path, len - 4, len);
	if (!ft_strsame(".cub", extention))
	{
		free(extention);
		return (1);
	}
	free(extention);
	return (0);
}

int		counter_check(int *counter)
{
	/*	Checks if every texture where present in the .cub file	*/

	int	i;

	i = 0;
	while (i < 6)
	{
		if (counter[i] == 0)	//maque un
			return (1);
		else if (counter[i] > 1) // de trop
			return (2);
		i++;
	}
	return (0);
}

void	extract_file( t_param *world, int fd)
{
	/* Extract the data except for the map	*/

	char	*holder;
	char	**split;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	world->counter = malloc(sizeof(int) * 6);
	if (!world->counter)
		error_exit("Malloc error ", world);
	while (i < 6)
		world->counter[i++] = 0;
	i = 1;
	while ((holder = get_next_line(fd)))
	{
		map_data_check(world, holder);
		split = ft_split(holder, ' ');
		extract_sand_rose(world, split);
		extract_f_c(world, split);
		if (counter_check(world->counter) == 2)
			error_exit("Corrupted .cub file 1", world);
		if (counter_check(world->counter) == 0 && flag <= 1)
		{
			world->map_start = i;
			if (ft_strlen(holder) > 1)
				flag++;
			// printf("map start : %d\n", world->map_start);
			// printf("holder : %s\n", holder);
		}
		i++;
	}
	extract_map(world);
}

void	cub_file_check_and_fill(t_param *world, char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd != -1)
		error_exit("This is a directory", world, NULL, -1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit("Failed to open the .cub file", world, NULL, -1);
	if (extention_check(path))
		error_exit("Not a .cub file", world, NULL, fd);
	world->path = ft_strdup(path);
	extract_file(world, fd);
	close(fd);
}
