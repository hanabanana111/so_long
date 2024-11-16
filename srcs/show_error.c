/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:52:02 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/28 18:39:44 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	show_error(const char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
}

void	show_error_exit(const char *str)
{
	show_error(str);
	exit(EXIT_FAILURE);
}

void	free_arr_error_exit(size_t i, char *fstr[], const char *str)
{
	size_t	j;

	j = 0;
	while (j < i)
		free(fstr[j++]);
	show_error_exit(str);
}
