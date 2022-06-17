/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:22:12 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/17 12:32:39 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>
# include <math.h>
# include <limits.h>
# include <float.h>

# define SIZE 64
# define ANGLEVISION 60
# define ECAR 0.025
// # define NBRAY ANGLEVISION / ECAR // ANGLEVISION / ECAR
# define SCREEN_HEIGHT 1200
// # define SCREEN_WIDTH NBRAY
# define NOSE 20
# define MOVE 0.1
# define ROTATE 5
// # define MID ANGLEVISION / 2 // ANGLEVISION / 2
// # define LIMIT MOVE * 3 // MOVE * 3
// # define HALF_SCREEN SCREEN_HEIGHT / 2 // SCREEN_HEIGHT / 2

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

typedef enum e_dir{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
	DO = 4,
	KE = 5,
	EN = 6,
}	t_dir;

typedef	struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		y_size;
	int		x_size;
}	t_data;

typedef struct s_param
{
	double			px_x_pos;	// Player x position in pixels
	double			px_y_pos;	// Player y position in pixels
	int				orient;		// Player orientation
	int				map_x_pos;	// Player x position in the map
	int				map_y_pos;	// Player y position in the map
	int				player_size;	// Length of side of square representing player
	int				flag_wall;
	int				nbray;		//value to replace macro fo the norm
	double			mid;
	double			limit;
	int				half_screen; 	// till here
	double			player_front;	// The ray laaunched just in front of the player
	double			player_left;
	double			player_right;
	double			player_back;
	double			dist_key;
	double			x_wallkey;
	t_bool			keyfound;
	t_bool			key_picked;
	char			**map;	// Actual map
	unsigned int	map_height;	// Amount of lines in the map
	unsigned int	map_width;	// Amount of columns in the map
	void			*video;	// MLX instance
	void			*window;	// MLX window
	t_data			*img;	// MLX image
	// t_data			*key;
	t_data			*calque;	// Something clean ??
	int				floor_color;	
	int				ceiling_color;
	// int				wall_color;
	char			*path;	// Path to the .cub file
	char			*no;	// Path to textures
	char			*so;
	char			*we;
	char			*ea;
	char			*door;
	t_data			*texture;
	int				*counter;	// Helps doing parsing
	unsigned int	map_start;
	t_bool			flag_front;
	t_bool			flag_back;
	t_bool			flag_right;
	t_bool			flag_left;
	t_bool			flag_rotateright;
	t_bool			flag_rotateleft;
	char			flag_frontdoor;
}	t_param;

// Drawing
void	init_window(t_param *world);
int		draw_view(t_param *world);
void	draw_col(t_param *world, double dist, double offset, double x_wall);
void	draw_key(t_param *world, double offset, double dist);

// Hooks
int		keyboard_press(int keycode, t_param *world);
int		keyboard_release(int keycode, t_param *world);
int		keyboard(t_param *world);
int		mouse_gest(int x, int y, t_param *world);
void	move_forward(t_param *world);
void	move_left(t_param *world);
void	move_right(t_param *world);
void	move_back(t_param *world);

// Minimap
void	draw_minimap(t_param *world);
void	paint_square_map(unsigned int x, unsigned int y, unsigned int square_length, t_param *world);
void	draw_player_nose(t_param *world, unsigned int square_length);

// Distance
double	calcul_dist_till_wall(t_param *world, double orientation, double *x_wall);
double	next_vert_wall(t_param *world, double orientation, double *vert_x_wall, int *sub_door_vert);
double	next_hor_wall(t_param *world, double orientation, double *hor_x_wall, int *sub_door_hor);

// Walls
int		check_left_wall(double y, double x, t_param *world);
int		check_right_wall(double y, double x, t_param *world);
int		check_up_wall(double y, double x, t_param *world);
int		check_down_wall(double y, double x, t_param *world);

// .cub file
void	cub_file_check_and_fill(t_param *world, char *path);
int		extention_check(const char *path);
void	extract_file( t_param *world, int fd);

// Map extractor
void	map_data_check(t_param *world, const char *holder);
int		valid_map_line(const char *holder);
void	extract_map(t_param *world);
void	get_player_position(t_param *world);
void	fill_spaces(t_param *world);
void	last_map_check(t_param *world);

// File extractor
void	extract_sand_rose(t_param *world, char **split);
void	extract_f_c(t_param *world, char **split);

// Utils
int		to_hex_int(const char *str, t_param *world);
size_t	len_array_2d(char **split);
int		create_trgb(int t, int r, int g, int b);
void	pixel_to_image(t_data *img, int x, int y, int color);
int		exit_cub3d(t_param *world);
double	degre_to_radiant(double degre);
void	bresenham(int x0, int y0, int x1, int y1, t_param *world);
char	*space_string(size_t len, t_param *world);
int		get_color_from_img(t_data *img, int x, int y);
void	check_max_int(long long int check, t_param *world);

// Errors
void	error_exit(char *message, t_param *world);

#endif

//to_do
// gnl leaks
// free on error
// norm
// key


