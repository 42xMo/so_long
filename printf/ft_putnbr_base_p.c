/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:31:07 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/07 19:33:45 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (i[str])
		++i;
	return (i);
}

int	ft_putnbr_base_p(unsigned long nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr >= (unsigned long)ft_strlen(base))
	{
		i += ft_putnbr_base_p(nbr / (unsigned long)ft_strlen(base), base);
		i += ft_putnbr_base_p(nbr % (unsigned long)ft_strlen(base), base);
	}
	if (nbr >= 0 && nbr < (unsigned long)ft_strlen(base))
		i += ft_putchar(base[nbr]);
	return (i);
}
