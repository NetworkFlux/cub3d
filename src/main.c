/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:19:31 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/17 13:25:37 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_world(t_param *world)
{
	/*	Clean init of the game structure	*/

	world->px_x_pos = 0;
	world->px_y_pos = 0;
	world->orient = 1000;
	world->map_x_pos = 0;
	world->map_y_pos = 0;
	world->player_size = 0;
	world->map = NULL;
	world->map_height = 0;
	world->map_width = 0;
	world->video = NULL;
	world->window = NULL;
	world->img = NULL;
	world->calque = NULL;
	world->floor_color = 0;
	world->ceiling_color = 0;
	// world->wall_color = 0;
	world->path = NULL;
	world->no = NULL;
	world->so = NULL;
	world->we = NULL;
	world->ea = NULL;
	world->door = "./texture/hell.xpm";
	world->counter = NULL;
	world->nbray = ANGLEVISION / ECAR;
	world->mid = ANGLEVISION / 2;
	world->limit = MOVE * 2;
	world->half_screen = SCREEN_HEIGHT / 2;
	world->flag_front = FALSE;
	world->flag_left = FALSE;
	world->flag_right = FALSE;
	world->flag_back = FALSE;
	world->flag_rotateright = FALSE;
	world->flag_rotateleft = FALSE;
	world->dist_key = -1;
	world->keyfound = FALSE;
	world->key_picked = FALSE;
	world->flag_anim = 0;
}

// static void	output_tests(t_param *world)
// {
// 	/*	Outputs some verification tests	*/

// 	int	i = 0;
// 	while (world->map[i])
// 		printf("%s\n", world->map[i++]);
// 	printf("Player (%d;%d), orientation : %d\n", world->map_x_pos, world->map_y_pos, world->orient);
// 	printf("Player (%d;%d), orientation : %d\n", world->px_x_pos, world->px_y_pos, world->orient);
// }

int	main(int argc, char **argv)
{
	t_param	*world;

	world = NULL;
	if (argc != 2)
		error_exit("[USAGE] ./cub3D <map.cub> ", world);
	world = malloc(sizeof(t_param));
	if (world)
	{
		init_world(world);
		cub_file_check_and_fill(world, argv[1]);
		world->px_x_pos = (world->map_x_pos) + 0.5;
		world->px_y_pos = (world->map_y_pos) + 0.5;
		// world->wall_color = create_trgb(0, 0, 0, 255);
		//output_tests(world);
		init_window(world);
		//free(world);
	}
	return (0);
}
