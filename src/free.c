/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:58:15 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/17 13:17:38 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_world(t_param *world)
{
	free_split(world->map);
	free(world->path);
	free(world->no);
	free(world->so);
	free(world->we);
	free(world->ea);
	free(world->counter);
	free(world->img);
	free(world->texture);
	free(world->calque);
	free(world);
}
