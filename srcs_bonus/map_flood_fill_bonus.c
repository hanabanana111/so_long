/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:38:45 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/28 20:55:41 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	flood_fill(t_game *game, t_flood_fill *ff, int x, int y)
{
	if (ff->map[y][x] == '*' || ff->map[y][x] == '1')
		return ;
	if (ff->map[y][x] == 'C')
		ff->count_c++;
	if (ff->map[y][x] == 'E')
	{
		ff->success++;
		return ;
	}
	ff->map[y][x] = '*';
	ff->height = y;
	flood_fill(game, ff, x + 1, y);
	flood_fill(game, ff, x - 1, y);
	flood_fill(game, ff, x, y + 1);
	flood_fill(game, ff, x, y - 1);
}

void	put_game_map_to_ff_map(t_game *game, t_flood_fill *ff)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < (size_t)game->height)
	{
		j = 0;
		while (j < (size_t)game->width)
		{
			ff->map[i][j] = game->map[i][j];
			j++;
		}
		ff->map[i][j] = '\0';
		i++;
	}
}

void	perform_flood_fill(t_game *game, t_flood_fill *ff, char c)
{
	size_t	i;

	i = 0;
	while (i < (size_t)game->height)
	{
		ff->map[i] = (char *)ft_calloc(game->width + 1, sizeof(char));
		if (!ff->map[i])
			free_arr_error_exit(i, ff->map, "flood fill malloc error");
		i++;
	}
	put_game_map_to_ff_map(game, ff);
	ff->map[game->player.p_y][game->player.p_x] = '0';
	flood_fill(game, ff, game->player.p_x, game->player.p_y);
	i = 0;
	while (i < (size_t)ff->height)
		free(ff->map[i++]);
	game->map[game->player.p_y][game->player.p_x] = c;
	if (ff->success && ff->count_c == game->c)
		return ;
	else
		show_error_exit("Invalid map. no way to get out(;;)");
}
