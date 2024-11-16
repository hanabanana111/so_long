/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:42:42 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/28 17:22:45 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_arr_error_exit_gnl(char *fstr, char *str)
{
	free(fstr);
	show_error_exit(str);
}

static int	ft_getchar(int fd, t_buf *p)
{
	if (p->n == 0)
	{
		p->n = read(fd, p->buf, BUFFER_SIZE);
		if (p->n < 0)
		{
			ft_bzero_gnl(p, sizeof(t_buf));
			return (READ_ERROR);
		}
		p->bufp = p->buf;
	}
	if (--(p->n) >= 0)
		return ((unsigned char)*(p->bufp)++);
	else
	{
		ft_bzero_gnl(p, sizeof(t_buf));
		return (EOF);
	}
}

char	*get_next_line(int fd)
{
	char			*pre;
	char			*result;
	char			c;
	static t_buf	bufs;

	result = NULL;
	while (fd >= 0)
	{
		pre = result;
		c = ft_getchar(fd, &bufs);
		if (c == EOF)
			break ;
		if (c == READ_ERROR)
			free_arr_error_exit_gnl(result, "read error");
		result = ft_strjoin_gnl(result, c);
		if (!result)
			free_arr_error_exit_gnl(pre, "ft_strjoin error");
		free(pre);
		if (c == '\n')
			break ;
	}
	return (result);
}
