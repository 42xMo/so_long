/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 08:01:58 by mabdessm          #+#    #+#             */
/*   Updated: 2024/09/02 19:18:31 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

unsigned int	ft_strstrlen(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		++i;
	return (i);
}

void	put_back_exit(t_data *data, int i, int j)
{
	(data->map)[j][i] = 'E';
	data->exit = 0;
}

void	check_end(t_data *data, char *str)
{
	change_player_texture(data, str);
	data->exit = 1;
	if (data->current_cats == data->total_cats)
	{
		printf("Number of Steps : %d\n", ++(data->steps));
		on_destroy(data);
	}
}
