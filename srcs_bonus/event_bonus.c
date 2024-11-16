/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:22:12 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/28 20:55:09 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	window_close(t_game *game)
{
	free_arr_exit(game->height, game->map, "window closed");
}

void	esc_window_close(int keycode, t_game *game)
{
	if (keycode == ON_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		free_arr_exit(game->height, game->map, "ESC pressed");
	}
}
