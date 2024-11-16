/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:39:29 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/29 15:12:03 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_one_img(t_game *gm, char *str)
{
	int	width;
	int	height;

	width = 48;
	height = 48;
	gm->img = mlx_xpm_file_to_image(gm->mlx, str, &width, &height);
	if (!gm->img)
		free_arr_error_exit(gm->height, gm->map, "image set failure");
}

void	set_one_img_and_put(t_game *gm, size_t y, size_t x, char *str)
{
	set_one_img(gm, str);
	mlx_put_image_to_window(gm->mlx, gm->win, gm->img, x * 48, y * 48);
}

void	set_map1(t_game *gm, size_t y, size_t x)
{
	if (gm->map[y][x] == '1')
		set_one_img(gm, WALL);
	else if (ft_strchr("0CEP", gm->map[y][x]))
		set_one_img(gm, GREEN);
	mlx_put_image_to_window(gm->mlx, gm->win, gm->img, x * 48, y * 48);
}

void	set_map2(t_game *gm, size_t y, size_t x)
{
	if (gm->map[y][x] == 'C')
		set_one_img(gm, COSMOS);
	else if (gm->map[y][x] == 'E')
		set_one_img(gm, GOAL);
	else if (gm->map[y][x] == 'P')
		set_one_img(gm, FAIRY1);
	if (ft_strchr("CEP", gm->map[y][x]))
		mlx_put_image_to_window(gm->mlx, gm->win, gm->img, x * 48, y * 48);
	if (!(gm->is_enemy) && gm->map[gm->height / 2][gm->width / 2] == '0')
	{
		gm->enemy.e_y = gm->height / 2;
		gm->enemy.e_x = gm->width / 2;
		set_one_img_and_put(gm, gm->enemy.e_y, gm->enemy.e_x, ENEMY);
		gm->is_enemy = 1;
	}
	else if (!(gm->is_enemy) && gm->map[y][x] == '0')
	{
		gm->enemy.e_y = y;
		gm->enemy.e_x = x;
		set_one_img_and_put(gm, gm->enemy.e_y, gm->enemy.e_x, ENEMY);
		gm->is_enemy = 1;
	}
}

void	minilibx_show_window(t_game *gm)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < (size_t)gm->height)
	{
		x = 0;
		while (x < (size_t)gm->width)
			set_map1(gm, y, x++);
		y++;
	}
	y = 0;
	while (y < (size_t)gm->height)
	{
		x = 0;
		while (x < (size_t)gm->width)
			set_map2(gm, y, x++);
		y++;
	}
	mlx_string_put(gm->mlx, gm->win, 24, 25, 0x000000, "step : ");
	mlx_key_hook(gm->win, (int (*)())key_hook, gm);
	mlx_hook(gm->win, ON_DESTROY, 0, (int (*)())window_close, gm);
	mlx_loop(gm->mlx);
}
