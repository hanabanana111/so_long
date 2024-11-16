/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:17:07 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/28 20:55:30 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	map_file_name_check(char *str)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	if (ft_strlen(str) < 5)
		show_error_exit("Invalid file to read map");
	i = len - 4;
	if (!ft_strnstr(&str[i], ".ber", 4) || str[i - 1] == '/')
		show_error_exit("Invalid file to read map");
}

void	struct_init(t_game *game, t_flood_fill *ff)
{
	ft_bzero((void *)game, sizeof(t_game));
	ft_bzero((void *)ff, sizeof(t_flood_fill));
}

void	treat_map(char *str, t_game *game, t_flood_fill *ff)
{
	map_file_name_check(str);
	struct_init(game, ff);
	open_read_map(str, game);
	map_check_01cep(game, ff);
}

void	treat_minilibx(t_game *gm)
{
	int	n;

	n = 48;
	gm->mlx = mlx_init();
	gm->win = mlx_new_window(gm->mlx, gm->width * n, gm->height * n, "so_long");
	minilibx_show_window(gm);
}

int	main(int argc, char *argv[])
{
	int				i;
	t_game			game;
	t_flood_fill	ff;

	i = 0;
	if (argc != 2)
		show_error_exit("Invalid arguments");
	treat_map(argv[1], &game, &ff);
	treat_minilibx(&game);
	while (1)
	{
		ft_printf("%s", game.map[i]);
		i++;
		if (!game.map[i])
			break ;
	}
	return (0);
}
