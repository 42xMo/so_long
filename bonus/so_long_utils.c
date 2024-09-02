/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 08:01:58 by mabdessm          #+#    #+#             */
/*   Updated: 2024/09/02 19:19:30 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
		on_destroy(data);
}

void	put_number_steps(t_data *data)
{
	char	*steps;
	char	*str;

	steps = ft_itoa(data->steps);
	str = ft_strjoin("Number of Steps : ", steps);
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->textures.width * 1.25,
		data->textures.height / 2, 0xFFFF00, str);
	free (steps);
	free (str);
}
