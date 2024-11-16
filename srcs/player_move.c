/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:53:46 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/29 15:20:06 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_steps(t_game *gm)
{
	size_t	x;
	char	*str;

	x = 0;
	str = ft_itoa(++(gm->step));
	while (x < (size_t)gm->width)
		set_one_img_and_put(gm, 0, x++, WALL);
	mlx_string_put(gm->mlx, gm->win, 24, 25, 0x000000, "step : ");
	mlx_string_put(gm->mlx, gm->win, 70, 25, 0x000000, str);
	free(str);
}

void	show_fairy_move(t_game *gm, char *str)
{
	set_one_img_and_put(gm, gm->player.pre_y, gm->player.pre_x, GREEN);
	set_one_img_and_put(gm, gm->player.p_y, gm->player.p_x, str);
	put_steps(gm);
}

void	left_right_up_down(int keycode, t_game *g, char *str)
{
	g->player.pre_x = g->player.p_x;
	g->player.pre_y = g->player.p_y;
	if (keycode == LEFT && g->map[g->player.p_y][g->player.p_x - 1] != '1')
	{
		g->player.p_x -= 1;
		show_fairy_move(g, str);
	}
	else if (keycode == RIGHT && g->map[g->player.p_y][g->player.p_x
		+ 1] != '1')
	{
		g->player.p_x += 1;
		show_fairy_move(g, str);
	}
	else if (keycode == UP && g->map[g->player.p_y - 1][g->player.p_x] != '1')
	{
		g->player.p_y -= 1;
		show_fairy_move(g, str);
	}
	else if (keycode == DOWN && g->map[g->player.p_y + 1][g->player.p_x] != '1')
	{
		g->player.p_y += 1;
		show_fairy_move(g, str);
	}
	set_one_img_and_put(g, g->enemy.e_y, g->enemy.e_x, ENEMY);
}

void	collect(t_game *gm)
{
	gm->map[gm->player.p_y][gm->player.p_x] = '0';
	(gm->flower)++;
	if (gm->c == gm->flower)
		gm->is_exit = 1;
}

void	key_hook(int keycode, t_game *gm)
{
	char	*fairy;

	esc_window_close(keycode, gm);
	if (gm->is_fin || (keycode != UP && keycode != DOWN && keycode != LEFT
			&& keycode != RIGHT))
		return ;
	fairy = FAIRY1;
	enemy_move(gm);
	if (gm->step % 2 == 0)
		fairy = FAIRY2;
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		left_right_up_down(keycode, gm, fairy);
	if (gm->map[gm->player.p_y][gm->player.p_x] == 'C')
		collect(gm);
	if (!gm->is_exit)
		set_one_img_and_put(gm, gm->goal.go_y, gm->goal.go_x, GOAL);
	if (gm->is_exit && gm->map[gm->player.p_y][gm->player.p_x] == 'E')
		success(gm);
	gameover(gm);
}
