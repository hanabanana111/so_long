/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobori <hakobori@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:57:52 by hakobori          #+#    #+#             */
/*   Updated: 2024/05/21 19:42:52 by hakobori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

static long	str_to_int64_within_range(const char *str, int flag)
{
	unsigned long	res;

	res = 0;
	while (*str && ft_isdigit(*str))
	{
		if (!flag && res > (unsigned long)LONG_MAX - (*str - '0') / 10)
			return (LONG_MAX);
		else if (flag && res > (unsigned long)LONG_MAX + 1 - (*str - '0') / 10)
			return (LONG_MIN);
		res = res * 10 + *str++ - '0';
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	res;

	sign = 0;
	res = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-');
	res = str_to_int64_within_range(str, sign);
	if (sign)
		res = -res;
	return ((int)res);
}
