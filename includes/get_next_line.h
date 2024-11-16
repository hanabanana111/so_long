/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:42:46 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/22 23:48:01 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42
# define READ_ERROR -2

typedef struct s_buf
{
	char	buf[BUFFER_SIZE];
	char	*bufp;
	int		n;
}			t_buf;

char		*get_next_line(int fd);
// utils
void		ft_bzero_gnl(void *s, size_t n);
size_t		ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin_gnl(char const *s1, char c);
void		ft_bzero(void *s, size_t n);

#endif
