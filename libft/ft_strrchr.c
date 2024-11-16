/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:59:41 by hakobori          #+#    #+#             */
/*   Updated: 2024/04/17 18:19:47 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s1;
	char	c2;

	s1 = (char *)s;
	c2 = (char)c;
	i = ft_strlen(s1);
	while (i >= 0)
	{
		if (s1[i] == c2)
			return (&s1[i]);
		i--;
	}
	return (NULL);
}
