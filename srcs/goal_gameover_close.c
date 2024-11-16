/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goal_gameover_close.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:53:55 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/29 14:01:04 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_arr_exit(size_t y, char *fstr[], char *str)
{
	size_t	i;

	i = 0;
	while (i < y)
		free(fstr[i++]);
	write(1, str, ft_strlen(str));
	exit(EXIT_SUCCESS);
}

void	gameover(t_game *gm)
{
	int	x;
	int	y;

	x = (gm->width / 2) * 48 - 48;
	y = (gm->height / 2) * 48;
	if (gm->player.p_x == gm->enemy.e_x && gm->player.p_y == gm->enemy.e_y)
	{
		mlx_clear_window(gm->mlx, gm->win);
		mlx_string_put(gm->mlx, gm->win, x, y, 0xff0000, "(x_x)GAMEOVER(x_x)");
	}
	if (gm->player.p_x == gm->enemy.pre_x && gm->player.p_y == gm->enemy.pre_y)
	{
		mlx_clear_window(gm->mlx, gm->win);
		mlx_string_put(gm->mlx, gm->win, x, y, 0xff0000, "(x_x)GAMEOVER(x_x)");
	}
}

void	success(t_game *gm)
{
	int	x;
	int	y;

	x = (gm->width / 2) * 48 - 48;
	y = (gm->height / 2) * 48;
	mlx_clear_window(gm->mlx, gm->win);
	mlx_string_put(gm->mlx, gm->win, x, y, 0xffffff, "!!!!!SUCSESS!!!!!");
	gm->is_fin = 1;
}
