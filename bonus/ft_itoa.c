/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:02:03 by mabdessm          #+#    #+#             */
/*   Updated: 2024/09/02 19:06:09 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	get_int_len(int n)
{
	int	len;

	len = 0;
	if (n < 0 || n == 0)
	{
		n = -n;
		++len;
	}
	while (n > 0)
	{
		n /= 10;
		++len;
	}
	return (len);
}

static char	*create_char(int n, int len, char *res)
{
	int	i;
	int	j;

	i = 0;
	j = len - 1;
	if (n < 0)
	{
		n = -n;
		res[i++] = '-';
	}
	while (i < len)
	{
		res[j--] = (n % 10) + 48;
		n /= 10;
		++i;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;

	if (n == -2147483648)
	{
		res = ft_strdup("-2147483648");
		return (res);
	}
	len = get_int_len(n);
	res = ft_calloc(sizeof(char), (len + 1));
	if (!res)
		return (NULL);
	res = create_char(n, len, res);
	return (res);
}
