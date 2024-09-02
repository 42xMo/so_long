/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 08:01:58 by mabdessm          #+#    #+#             */
/*   Updated: 2024/09/02 19:53:47 by mabdessm         ###   ########.fr       */
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

void	draw_textures2(t_data *data, int i, int x, int ii)
{
	int	jj;
	int	j;

	jj = 0;
	j = get_player_i_pos(data) - ((x / 2) - 1) - 1;
	while ((j + x + 1) > data->width)
		--j;
	if (j < 0)
		j = -1;
	while (data->map[i][++j])
	{
		if (data->map[i][j] == '1')
			put_image(data, data->textures.wall_texture, ii, jj++);
		if (data->map[i][j] == '0')
			put_image(data, data->textures.floor_texture, ii, jj++);
		if (data->map[i][j] == 'P')
			put_image(data, data->textures.player_texture, ii, jj++);
		data->cat_color = i * j;
		if (data->map[i][j] == 'C')
			draw_collectibles(data, ii, jj++);
		if (data->map[i][j] == 'E')
			put_image(data, data->textures.exit_texture, ii, jj++);
		if (data->map[i][j] == 'F')
			put_image(data, data->textures.enemy1_texture, ii, jj++);
	}
}
