/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_extractor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:29:58 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/14 14:04:37 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	extract_sand_rose(t_param *world, char **split)
{
	/*	Gets the textures for every directions	*/

	if (len_array_2d(split) == 2)
	{
		if (ft_strsame(split[0], "NO"))
		{
			world->no = split[1];
			world->counter[0] += 1;
		}
		else if (ft_strsame(split[0], "SO"))
		{
			world->so = split[1];
			world->counter[1] += 1;
		}
		else if (ft_strsame(split[0], "WE"))
		{
			world->we = split[1];
			world->counter[2] += 1;
		}
		else if (ft_strsame(split[0], "EA"))
		{
			world->ea = split[1];
			world->counter[3] += 1;
		}
	}
}

void	extract_f_c(t_param *world, char **split)
{
	/*	Gets the textures for the ceiling and floor	*/

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
