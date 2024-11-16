/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:33:03 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/28 17:23:13 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	str_is_c(char *str, char c, size_t n)
{
	size_t	i;

	i = 0;
	while (i <= n && str[i] == c)
		i++;
	if (!str[i] || str[i] == '\n')
		return (1);
	return (0);
}

void	map_wall_check(t_game *game, int y)
{
	int	x;

	x = 0;
	while (game->map[y][x] && game->map[y][x] != '\n')
	{
		if (y == 0 || y == game->height - 1)
		{
			if (!str_is_c(game->map[y], '1', game->width))
				free_arr_error_exit(game->height, game->map, "map(wall error)");
			break ;
		}
		if ((x == 0 || x == game->width - 1) && game->map[y][x] != '1')
			free_arr_error_exit(game->height, game->map, "map(wall error)");
		x++;
	}
}
