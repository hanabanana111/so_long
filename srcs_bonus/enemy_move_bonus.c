/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:30:02 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/29 15:14:55 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	ft_random(void)
{
	static int	x = 10;
	int			a;
	int			b;
	int			c;
	double		res;

	a = 1103515245;
	b = 12345;
	c = 2147483647;
	x = (a * x + b) & c;
	res = (int)(((double)x + 1.0) / ((double)c + 2.0) * 10);
	return (res);
}

void	put_cosmos_banana(t_game *game, int x, int y)
{
	if (game->map[y][x] != 'C' && game->map[y][x] != 'E')
		return ;
	else if (game->map[y][x] == 'C')
		set_one_img_and_put(game, y, x, COSMOS);
	else if (game->map[y][x] == 'E')
		set_one_img_and_put(game, y, x, GOAL);
}

void	go_to_up_down(t_game *game, int random)
{
	game->enemy.pre_x = game->enemy.e_x;
	game->enemy.pre_y = game->enemy.e_y;
	if (random >= 6 && random < 8)
	{
		if (game->map[game->enemy.e_y - 1][game->enemy.e_x] == '1')
			return ;
		set_one_img_and_put(game, game->enemy.e_y, game->enemy.e_x, GREEN);
		put_cosmos_banana(game, game->enemy.e_x, game->enemy.e_y);
		game->enemy.e_y -= 1;
	}
	else if (random >= 8 && random < 10)
	{
		if (game->map[game->enemy.e_y + 1][game->enemy.e_x] == '1')
			return ;
		set_one_img_and_put(game, game->enemy.e_y, game->enemy.e_x, GREEN);
		put_cosmos_banana(game, game->enemy.e_x, game->enemy.e_y);
		game->enemy.e_y += 1;
	}
}

void	go_to_left_right(t_game *game, int random)
{
	game->enemy.pre_x = game->enemy.e_x;
	game->enemy.pre_y = game->enemy.e_y;
	if (random >= 0 && random < 3)
	{
		if (game->map[game->enemy.e_y][game->enemy.e_x - 1] == '1')
			return ;
		set_one_img_and_put(game, game->enemy.e_y, game->enemy.e_x, GREEN);
		put_cosmos_banana(game, game->enemy.e_x, game->enemy.e_y);
		game->enemy.e_x -= 1;
	}
	else if (random >= 3 && random < 6)
	{
		if (game->map[game->enemy.e_y][game->enemy.e_x + 1] == '1')
			return ;
		set_one_img_and_put(game, game->enemy.e_y, game->enemy.e_x, GREEN);
		put_cosmos_banana(game, game->enemy.e_x, game->enemy.e_y);
		game->enemy.e_x += 1;
	}
}

void	enemy_move(t_game *game)
{
	int	random;

	random = ft_random();
	if (random < 6)
		go_to_left_right(game, random);
	else if (random >= 6)
		go_to_up_down(game, random);
}
