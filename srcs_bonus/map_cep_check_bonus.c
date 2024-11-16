/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cep_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:28:51 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/28 20:55:35 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_struct_xy(int x, int y, t_game *game, char *str)
{
	if (ft_strnstr(str, "player", 6))
	{
		game->player.p_x = x;
		game->player.p_y = y;
	}
	else if (ft_strnstr(str, "goal", 4))
	{
		game->goal.go_x = x;
		game->goal.go_y = y;
	}
}

static int	c_count(t_game *game, int y, char c)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (game->map[y][x] && game->map[y][x] != '\n')
	{
		if (y == 0 || y == game->height - 1)
			break ;
		if (x > 0 && x < game->width)
		{
			if (game->map[y][x] == c)
			{
				if (c == 'P')
					put_struct_xy(x, y, game, "player");
				else if (c == 'E')
					put_struct_xy(x, y, game, "goal");
				count++;
			}
			if (!ft_strchr("10CEP", (int)game->map[y][x]))
				free_arr_error_exit(++y, game->map, "Invalid map");
		}
		x++;
	}
	return (count);
}

void	count_cep(t_game *game, int y)
{
	game->c += c_count(game, y, 'C');
	game->e += c_count(game, y, 'E');
	game->p += c_count(game, y, 'P');
}

void	counted_cep_check(t_game *game)
{
	if (game->e != 1)
		free_arr_error_exit(game->height, game->map, "map(E number)");
	if (game->p != 1)
		free_arr_error_exit(game->height, game->map, "map(P number)");
	if (game->c == 0)
		free_arr_error_exit(game->height, game->map, "map(C number)");
}

void	map_check_01cep(t_game *game, t_flood_fill *ff)
{
	int	y;

	y = 0;
	while (y < game->height)
	{
		map_wall_check(game, y);
		count_cep(game, y);
		y++;
	}
	counted_cep_check(game);
	perform_flood_fill(game, ff, 'P');
}
