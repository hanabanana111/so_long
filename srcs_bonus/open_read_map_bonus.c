/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:22:35 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/28 20:55:56 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static size_t	ft_strlen_so_long(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}

void	open_read_map(char *file, t_game *game)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1 || fd > OPEN_MAX)
		show_error_exit("open error");
	while (1)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i])
			break ;
		if (game->width && game->width != (int)ft_strlen_so_long(game->map[i]))
			free_arr_error_exit(i, game->map, "map(wrong width)");
		if (!game->width)
			game->width = ft_strlen_so_long(game->map[i]);
		game->height++;
		i++;
		if (game->height >= 1000)
			free_arr_error_exit(i, game->map, "map(too many height)");
	}
	close(fd);
	if (game->height < 3)
		free_arr_error_exit(i, game->map, "map(too few height)");
}
