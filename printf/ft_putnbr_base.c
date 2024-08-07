/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:34:52 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/07 19:32:18 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr >= (unsigned int)ft_strlen(base))
	{
		i += ft_putnbr_base(nbr / (unsigned int)ft_strlen(base), base);
		i += ft_putnbr_base(nbr % (unsigned int)ft_strlen(base), base);
	}
	if (nbr >= 0 && nbr < (unsigned int)ft_strlen(base))
		i += ft_putchar(base[nbr]);
	return (i);
}
