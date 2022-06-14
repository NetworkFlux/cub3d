/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:34:50 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/13 12:30:37 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		extention_check(const char *path)
{
	/*	Checks if the extension (.cub) is valid.	*/

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
		if (counter[i++] != 1)
			return (1);
	}
	return (0);
}

void	extract_file( t_param *world, int fd)
{
	/* Extract the data except for the map	*/

	char	*holder;
	char	**split;
	int		i;

	i = 0;
	world->counter = malloc(sizeof(int) * 6);
	if (!world->counter)
		error_exit("Malloc error ", world);
	while (i < 6)
		world->counter[i++] = 0;
	while (get_next_line(fd, &holder))
	{
		map_data_check(world, holder);
		split = ft_split(holder, ' ');
		extract_sand_rose(world, split);
		extract_f_c(world, split);
	}
	if (counter_check(world->counter))
		error_exit("Corrupted .cub file ", world);
	extract_map(world);
}

void	cub_file_check_and_fill(t_param *world, char *path)
{
	/*	Handels the entire extraction based on the the .cub file path.	*/
	
	int		fd;
	world->path = path;
	fd = open(path, O_DIRECTORY);
	if (fd != -1)
		error_exit("This is a directory ", world);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit("Failed to open the .cub file ", world);
	if (extention_check(path))
		error_exit("Not a .cub file ", world);
	extract_file(world, fd);
}
