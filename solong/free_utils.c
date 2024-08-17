/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 07:51:38 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/17 07:53:29 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_tab(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
		free (str[i]);
	free (str);
}

int	free_and_return(char **tab, char c)
{
	if (c == 'e')
	{
		ft_free_tab(tab);
		return (return_error("No valid exit path!"));
	}
	else
	{
		ft_free_tab(tab);
		return (return_error("No valid collectibles path!"));
	}
}

void	double_free(char *str1, char *str2)
{
	free (str1);
	free (str2);
}
