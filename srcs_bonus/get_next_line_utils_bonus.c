/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:42:40 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/28 20:55:19 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_bzero_gnl(void *s, size_t n)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char *)s;
	while (i < n)
		s2[i++] = '\0';
}

static size_t	ft_strlen_gnl(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen_gnl(src));
}

static char	*ft_strdup_gnl(const char *s1)
{
	int		i;
	char	*s1_cpy;

	i = 0;
	s1_cpy = (char *)malloc(sizeof(char) * (ft_strlen_gnl(s1) + 1));
	if (!s1_cpy)
		return (NULL);
	while (s1[i])
	{
		s1_cpy[i] = s1[i];
		i++;
	}
	s1_cpy[i] = '\0';
	return (s1_cpy);
}

char	*ft_strjoin_gnl(char const *s1, char c)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;
	char	s2[2];

	s2[0] = c;
	s2[1] = '\0';
	if (!s1 && !c)
		return (ft_strdup_gnl(""));
	if (!s1 && c)
		return (ft_strdup_gnl(s2));
	if (s1 && !c)
		return (ft_strdup_gnl(s1));
	s1_len = ft_strlen_gnl(s1);
	s2_len = 1;
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy_gnl(result, s1, s1_len + 1);
	ft_strlcpy_gnl(result + s1_len, s2, s2_len + 1);
	return (result);
}
