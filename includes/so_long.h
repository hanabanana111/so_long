/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:33:50 by hakobori          #+#    #+#             */
/*   Updated: 2024/09/26 21:00:12 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_player
{
	int				p_x;
	int				p_y;
	int				pre_x;
	int				pre_y;
}					t_player;

typedef struct s_enemy
{
	int				e_x;
	int				e_y;
	int				pre_x;
	int				pre_y;
}					t_enemy;

typedef struct s_goal
{
	int				go_x;
	int				go_y;
}					t_goal;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	unsigned int	c;
	int				e;
	int				p;
	char			*map[1000];
	void			*img;
	int				is_exit;
	int				is_enemy;
	int				is_fin;
	unsigned int	step;
	unsigned int	flower;
	t_player		player;
	t_enemy			enemy;
	t_goal			goal;
}					t_game;

typedef struct s_flood_fill
{
	char			*map[1000];
	int				width;
	int				height;
	int				is_wall;
	int				success;
	unsigned int	count_c;
}					t_flood_fill;

# define FAIRY1 "textures/fairy1.xpm"
# define FAIRY2 "textures/fairy2.xpm"
# define COSMOS "textures/cosmos.xpm"
# define GREEN "textures/green.xpm"
# define WALL "textures/wall.xpm"
# define GOAL "textures/banana.xpm"
# define ENEMY "textures/kaseijin.xpm"
# define ON_DESTROY 17
# define ON_ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define OPEN_MAX 2000

// open_read_map
void				open_read_map(char *file, t_game *game);
int					str_is_c(char *str, char c, size_t n);

// map_wall_check
void				map_wall_check(t_game *game, int y);

// map_cep_check
void				count_cep(t_game *game, int y);
void				counted_cep_check(t_game *game);
void				map_check_01cep(t_game *game, t_flood_fill *ff);

// map_flood_fill
void				perform_flood_fill(t_game *game, t_flood_fill *ff, char c);

// minilibx_set
void				set_one_img_and_put(t_game *gm, size_t y, size_t x,
						char *str);
void				set_one_img(t_game *gm, char *str);
void				minilibx_show_window(t_game *game);

// player_move
void				key_hook(int keycode, t_game *gm);

// show_error
void				show_error(const char *str);
void				show_error_exit(const char *str);
void				free_arr_error_exit(size_t i, char *fstr[],
						const char *str);

// goal_gameover_close
void				free_arr_exit(size_t y, char *fstr[], char *str);
void				window_close(t_game *game);
void				esc_window_close(int keycode, t_game *game);
void				success(t_game *gm);

// enemy_move
void				enemy_move(t_game *game);
void				gameover(t_game *game);

// event
void				window_close(t_game *game);
void				esc_window_close(int keycode, t_game *game);

#endif