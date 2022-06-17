/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:19:31 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/17 16:50:00 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   Updated: 2022/06/17 01:49:33 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	debug(t_param *world)
{
	int	i;

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
	i = 0;
	printf(" ===== START DEBUG ===== \n");
	while (world->map[i])
		printf("%s\n", world->map[i++]);
	printf("-----------------------------\n");
	printf("Player px x pos : %f\n", world->px_x_pos);
	printf("Player px y pos : %f\n", world->px_y_pos);
	printf("Player map x pos : %d\n", world->map_x_pos);
	printf("Player map y pos : %d\n", world->map_y_pos);
	printf("Player orientation : %d\n", world->orient);
	printf("-----------------------------\n");
	printf("Map height : %d\n", world->map_height);
	printf("Map width : %d\n", world->map_width);
	printf("-----------------------------\n");
	printf("Map start : %d\n", world->map_start);
	printf("-----------------------------\n");
	printf("Map .cub path : %s\n", world->path);
	printf("Map NO path : %s\n", world->no);
	printf("Map SO path : %s\n", world->so);
	printf("Map WE path : %s\n", world->we);
	printf("Map EA path : %s\n", world->ea);
	printf("-----------------------------\n");
	printf("Map floor color : %d\n", world->floor_color);
	printf("Map ceiling color : %d\n", world->ceiling_color);
	printf(" ===== END DEBUG ===== \n");
}

int	main(int argc, char **argv)
{
	t_param	*world;

	world = NULL;
	if (argc != 2)
		error_exit("[USAGE] ./cub3D <map.cub>", world, NULL, -1);
	world = malloc(sizeof(t_param));
	if (world)
	{
		init_world(world);
		cub_file_check_and_fill(world, argv[1]);
		debug(world);
		lets_cub(world);
		system("leaks cub3D");
	}
	else
		error_exit("Malloc error", world, NULL, -1);
	return (0);
}
